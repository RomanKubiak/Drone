/*
  ==============================================================================

    MainComponent.h
    Created: 20 Nov 2015 2:17:34pm
    Author:  r.kubiak

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "DSynthUI.h"
#include "MaxFilter.h"

class OscTriangle
{
	public:
		float tick();
		void setFrequency(double _frequency) { frequency = _frequency; }
		float phase;
		double sampleRate;
		double frequency;
};

class MainComponent   : public AudioAppComponent
{
	public:
		MainComponent();
		~MainComponent();
		void prepareToPlay (int samplesPerBlockExpected, double sampleRate);
		void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill);
		void releaseResources();
		void paint (Graphics& g);
		void resized();
		void setNoiseLevelAR(float a, float r);
		void setOscLevelAR(float a, float r);
		void setOscFreqAR(float a, float r);
		void setOscFreq(float f);
		void setNoiseLevel(float level);
		float waveshape(float in);
		void setOscShape(uint8_t shape);
		void setWaveshape(bool _doWaveshape);
		void processDistortion(AudioSampleBuffer &buffer);
		void setDistortionType(uint8_t type);
		void setNoiseFilter(double cutoff, double resonance);
		enum OscType
		{
			Sin,
			Saw,
			Square,
			Triangle,
			None
		};
		enum DistType
		{
			hardClipping = 0,
			softClipping,
			softClippingExp,
			fullWaveRectifier,
			halfWaveRectifier,
			NoDistortion
		};
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)

	private:
		maxiFilter hpFilter;
		float distGainIndB;
		ReadWriteLock audioLock;
		double sRate;
		stk::SineWave oscSin;
		stk::BlitSaw oscSaw;
		stk::BlitSquare oscSquare;
		stk::ADSR oscFreqAR;
		stk::ADSR oscLevelAR;
		stk::ADSR noiseLevelAR;
		stk::Noise noise;
		OscTriangle oscTriangle;
		double timeInSamples;
		float noiseLevel;
		float oscBaseFreq;
		DSynthUI ui;
		OscType oscType;
		bool doWaveshape;
		DistType distortionType;
		double noiseFilterCutoff;
		double noiseFilterResonance;
};

#endif  // MAINCOMPONENT_H_INCLUDED
