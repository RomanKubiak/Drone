#ifndef DRONE_ENGINE_H
#define DRONE_ENGINE_H

#include "../JuceLibraryCode/JuceHeader.h"

struct DroneSound : public SynthesiserSound
{
    DroneSound() {}

    bool appliesToNote (int /*midiNoteNumber*/) override        { return true; }
    bool appliesToChannel (int /*midiChannel*/) override        { return true; }
};

class DroneSingle : public SynthesiserVoice
{
	public:
		DroneSingle();
		enum Shape
		{
			Sine,
			Saw
		};
		bool canPlaySound (SynthesiserSound* sound);
		void startNote (int midiNoteNumber, float velocity, SynthesiserSound*, int /*currentPitchWheelPosition*/);
		void startNoteSine (int midiNoteNumber, float velocity, SynthesiserSound*, int /*currentPitchWheelPosition*/);
		void startNoteSaw (int midiNoteNumber, float velocity, SynthesiserSound*, int /*currentPitchWheelPosition*/);
		void stopNote (float /*velocity*/, bool allowTailOff);
		void pitchWheelMoved (int /*newValue*/) {}
		void controllerMoved (int /*controllerNumber*/, int /*newValue*/) {}
		void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples);
		void renderNextSineBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples);
		void renderNextSawBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples);
		void setOffset(const double _offset);
		void setShape(const Shape _shape);

	private:
		double currentAngle, angleDelta, level, tailOff, offset;
		int lastNoteNumber;
		stk::BlitSaw stkSaw;
		Shape currentShape;
};

class DroneBundle : public SynthesiserVoice
{
	public:
		DroneBundle();
		~DroneBundle();
		void startNote (int midiNoteNumber, float velocity, SynthesiserSound*, int /*currentPitchWheelPosition*/);
		bool canPlaySound (SynthesiserSound* sound);
		void stopNote (float /*velocity*/, bool allowTailOff);
		void pitchWheelMoved (int /*newValue*/) {}
		void controllerMoved (int /*controllerNumber*/, int /*newValue*/);
		void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples);
		void setOffset(uint8 voiceIndex, double offset);

	private:
		DroneSingle voice[8];
};

#endif
