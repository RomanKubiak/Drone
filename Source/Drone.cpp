/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "Drone.h"
#include "DroneUI.h"
#include "DroneEngine.h"

Drone::Drone() : hold(false)
{
	droneUI = new DroneUI(*this, keyboardState);
    setSize (600, 600);
    setAudioChannels (0, 2);
    addAndMakeVisible (droneUI);

    synth.addVoice(new DroneBundle());
    synth.addSound (new DroneSound());
}

Drone::~Drone()
{
    shutdownAudio();
}

    //=======================================================================
void Drone::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
	midiCollector.reset (sampleRate);
	synth.setCurrentPlaybackSampleRate (sampleRate);
	reverb.setSampleRate(sampleRate);
	reverb.reset();
	stk::Stk::setSampleRate(sampleRate);
	droneDelay.prepareToPlay(sampleRate, samplesPerBlockExpected);
}

void Drone::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
	bufferToFill.clearActiveBufferRegion();
	MidiBuffer incomingMidiRaw;
	MidiBuffer incomingMidiExpected;
	midiCollector.removeNextBlockOfMessages (incomingMidiRaw, bufferToFill.numSamples);
	keyboardState.processNextMidiBuffer (incomingMidiRaw, 0, bufferToFill.numSamples, true);

	MidiMessage m;
	int stamp;
	MidiBuffer::Iterator it(incomingMidiRaw);
	while (it.getNextEvent(m, stamp))
	{
		if (m.isNoteOff() && hold)
			continue;

		incomingMidiExpected.addEvent(m, stamp);
	}

	synth.renderNextBlock (*bufferToFill.buffer, incomingMidiExpected, 0, bufferToFill.numSamples);

	droneDelay.processBlock(*bufferToFill.buffer, incomingMidiExpected);

	bufferToFill.buffer->applyGain(0.005f);

	if (bufferToFill.buffer->getNumChannels() == 2)
		reverb.processStereo(bufferToFill.buffer->getWritePointer(0), bufferToFill.buffer->getWritePointer(1), bufferToFill.numSamples);
	else
		reverb.processMono(bufferToFill.buffer->getWritePointer(0), bufferToFill.numSamples);
}

void Drone::releaseResources()
{
}

void Drone::paint (Graphics& g)
{
	g.fillAll (Colours::black);
}

void Drone::resized()
{
	droneUI->setBounds(getBounds());
}

void Drone::setOffset (uint8 bundle, uint8 voice, double offset)
{
	Logger::writeToLog("Offset voice:"+String(voice)+" offset:"+String(offset));
	MidiMessage m = MidiMessage::controllerEvent(1, voice, (uint8)(50 + offset));
	m.setTimeStamp(1);
	midiCollector.addMessageToQueue(m);
}

void Drone::setShape (uint8 bundle, uint8 voice, bool isSaw)
{
	MidiMessage m = MidiMessage::controllerEvent(1, 10 + voice, isSaw ? 63 : 0);
	m.setTimeStamp(1);
	midiCollector.addMessageToQueue(m);
}

void Drone::setHold(const bool _hold)
{
	hold = _hold;
	synth.allNotesOff(1,false);
}

void Drone::setReverb(double roomSize, double damping, double wetLevel, double dryLevel, double width, bool freezeMode)
{
	reverbParameters.roomSize	= roomSize / 255.0;
	reverbParameters.damping 	= damping / 255.0;
	reverbParameters.wetLevel 	= wetLevel / 255.0;
	reverbParameters.dryLevel 	= dryLevel / 255.0;
	reverbParameters.width 		= width / 255.0;
	reverbParameters.freezeMode = freezeMode ? 1.0f : 0.0f;

    reverb.setParameters(reverbParameters);
}

void Drone::setDelay(double length, double wetLevel, double dryLevel, double feedbackLevel)
{
	Logger::writeToLog("Drone::setDelay l:"+String(length)+" wet:"+String(wetLevel)+" dry:"+String(dryLevel)+" fbk:"+String(feedbackLevel));
	droneDelay.setParameter(DroneDelayProcessor::kDelayLengthParam, length);
	droneDelay.setParameter(DroneDelayProcessor::kWetMixParam, wetLevel / 255.0);
	droneDelay.setParameter(DroneDelayProcessor::kDryMixParam, dryLevel / 255.0);
	droneDelay.setParameter(DroneDelayProcessor::kFeedbackParam, feedbackLevel / 255.0);
}

void Drone::resetDelay()
{
	droneDelay.reset();
}

Component* createMainContentComponent()     { return new Drone(); }

#endif  // MAINCOMPONENT_H_INCLUDED
