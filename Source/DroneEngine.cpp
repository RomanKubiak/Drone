#include "DroneEngine.h"

DroneSingle::DroneSingle() 
	: currentAngle (0), angleDelta (0), level (0), tailOff (0), offset(0), lastNoteNumber(-1),
		currentShape(Sine)
{
}

bool DroneSingle::canPlaySound (SynthesiserSound* sound)
{
	return dynamic_cast<DroneSound*> (sound) != nullptr;
}

void DroneSingle::startNote (int midiNoteNumber, float velocity, SynthesiserSound *ssound, int currentPitchWheelPosition)
{
	switch (currentShape)
	{
	case Sine:
		startNoteSine(midiNoteNumber, velocity, ssound, currentPitchWheelPosition);
	case Saw:
		startNoteSaw(midiNoteNumber, velocity, ssound, currentPitchWheelPosition);
	}

	lastNoteNumber = midiNoteNumber;
}

void DroneSingle::startNoteSine (int midiNoteNumber, float velocity, SynthesiserSound*, int /*currentPitchWheelPosition*/)
{
	currentAngle = 0.0;
	level = velocity * 0.15;
	tailOff = 0.0;

	double cyclesPerSecond = MidiMessage::getMidiNoteInHertz (midiNoteNumber) + offset;
	double cyclesPerSample = cyclesPerSecond / getSampleRate();

	angleDelta = cyclesPerSample * 2.0 * double_Pi;
}

void DroneSingle::startNoteSaw (int midiNoteNumber, float velocity, SynthesiserSound*, int /*currentPitchWheelPosition*/)
{
	stkSaw.setFrequency(MidiMessage::getMidiNoteInHertz (midiNoteNumber) + offset);
}

void DroneSingle::setOffset(const double _offset)
{
	offset = _offset;
	startNote(lastNoteNumber,1.0f, nullptr, -1);
}

void DroneSingle::setShape(const Shape _shape)
{
	currentShape = _shape;
	startNote(lastNoteNumber,1.0f, nullptr, -1);
}

void DroneSingle::stopNote (float /*velocity*/, bool allowTailOff)
{
	clearCurrentNote();
	angleDelta = 0.0;
	stkSaw.reset();
}

void DroneSingle::renderNextSineBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
	if (angleDelta != 0.0)
	{
		if (tailOff > 0)
		{
			while (--numSamples >= 0)
			{
				const float currentSample = (float) (std::sin (currentAngle) * level * tailOff);

				for (int i = outputBuffer.getNumChannels(); --i >= 0;)
					outputBuffer.addSample (i, startSample, currentSample);

				currentAngle += angleDelta;
				++startSample;

				tailOff *= 0.99;

				if (tailOff <= 0.005)
				{
					clearCurrentNote();

					angleDelta = 0.0;
					break;
				}
			}
		}
		else
		{
			while (--numSamples >= 0)
			{
				const float currentSample = (float) (std::sin (currentAngle) * level);
				for (int i = outputBuffer.getNumChannels(); --i >= 0;)
					outputBuffer.addSample (i, startSample, currentSample);
				currentAngle += angleDelta;
				++startSample;
			}
		}
	}
}

void DroneSingle::renderNextSawBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
	for (int ch = 0; ch<outputBuffer.getNumChannels(); ch++)
	{
		for (int i=0; i<numSamples; i++)
		{
			outputBuffer.setSample(ch, startSample+i, stkSaw.tick());
		}
	}
	outputBuffer.applyGain(0.2f);
}

void DroneSingle::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
	switch (currentShape)
	{
	case Sine:
		renderNextSineBlock(outputBuffer, startSample, numSamples);
		break;
	case Saw:
		renderNextSawBlock(outputBuffer, startSample, numSamples);
		break;
	}
}

/*
 * Bundle
 */
DroneBundle::DroneBundle()
{
}

DroneBundle::~DroneBundle()
{
}

bool DroneBundle::canPlaySound (SynthesiserSound* sound)
{
	return dynamic_cast<DroneSound*> (sound) != nullptr;
}

void DroneBundle::startNote (int midiNoteNumber, float velocity, SynthesiserSound *ssound, int currentPitchWheelPosition)
{
	voice[0].startNote(midiNoteNumber, velocity, ssound, currentPitchWheelPosition);
	voice[1].startNote(midiNoteNumber, velocity, ssound, currentPitchWheelPosition);
	voice[2].startNote(midiNoteNumber, velocity, ssound, currentPitchWheelPosition);
	voice[3].startNote(midiNoteNumber, velocity, ssound, currentPitchWheelPosition);
	voice[4].startNote(midiNoteNumber, velocity, ssound, currentPitchWheelPosition);
	voice[5].startNote(midiNoteNumber, velocity, ssound, currentPitchWheelPosition);
	voice[6].startNote(midiNoteNumber, velocity, ssound, currentPitchWheelPosition);
	voice[7].startNote(midiNoteNumber, velocity, ssound, currentPitchWheelPosition);
}

void DroneBundle::stopNote (float velocity, bool allowTailOff)
{
	voice[0].stopNote(velocity, allowTailOff);
	voice[1].stopNote(velocity, allowTailOff);
	voice[2].stopNote(velocity, allowTailOff);
	voice[3].stopNote(velocity, allowTailOff);
	voice[4].stopNote(velocity, allowTailOff);
	voice[5].stopNote(velocity, allowTailOff);
	voice[6].stopNote(velocity, allowTailOff);
	voice[7].stopNote(velocity, allowTailOff);
}

void DroneBundle::controllerMoved (int controllerNumber, int newValue)
{
	if (controllerNumber >= 0 && controllerNumber <= 7)
	{
		if (newValue >= 0 && newValue <= 100)
			voice[controllerNumber].setOffset(newValue - 50);
	}
	else if (controllerNumber >= 10 && controllerNumber <= 17)
	{
		voice[controllerNumber-10].setShape(newValue ? DroneSingle::Saw : DroneSingle::Sine);
	}
}

void DroneBundle::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    voice[0].renderNextBlock(outputBuffer, startSample, numSamples);
    voice[1].renderNextBlock(outputBuffer, startSample, numSamples);
    voice[2].renderNextBlock(outputBuffer, startSample, numSamples);
    voice[3].renderNextBlock(outputBuffer, startSample, numSamples);
    voice[4].renderNextBlock(outputBuffer, startSample, numSamples);
    voice[5].renderNextBlock(outputBuffer, startSample, numSamples);
    voice[6].renderNextBlock(outputBuffer, startSample, numSamples);
    voice[7].renderNextBlock(outputBuffer, startSample, numSamples);
}

void DroneBundle::setOffset(uint8 voiceIndex, double offset)
{
	if (voiceIndex <= 7)
	{
		voice[voiceIndex].setOffset(offset);
	}
}
