/*
  ==============================================================================

    DroneMainComponent.h
    Created: 16 Nov 2015 4:56:48pm
    Author:  r.kubiak

  ==============================================================================
*/

#ifndef DRONEMAINCOMPONENT_H_INCLUDED
#define DRONEMAINCOMPONENT_H_INCLUDED

#include "JuceHeader.h"

#include "DroneUI.h"

class Drone   : public AudioAppComponent
{
	public:
		Drone();
		~Drone();
		void prepareToPlay (int samplesPerBlockExpected, double sampleRate);
		void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill);
		void releaseResources();
		void paint (Graphics& g);
		void resized();
        void setOffset (uint8 bundle, uint8 voice, double offset);
		void setShape (uint8 bundle, uint8 voice, bool isSaw);
        void setHold(const bool _hold);

	private:
		MidiKeyboardState keyboardState;
		MidiMessageCollector midiCollector;
		Synthesiser synth;
		ScopedPointer<DroneUI> droneUI;
		bool hold;
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Drone)
};



#endif  // DRONEMAINCOMPONENT_H_INCLUDED
