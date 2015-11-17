/*
  ==============================================================================

    DroneMainComponent.h
    Created: 16 Nov 2015 4:56:48pm
    Author:  r.kubiak

  ==============================================================================
*/

#ifndef DRONEMAINCOMPONENT_H_INCLUDED
#define DRONEMAINCOMPONENT_H_INCLUDED

class DroneMainComponent   : public AudioAppComponent
{
	public:
		DroneMainComponent() : droneUI(keyboardState)
		~MainContentComponent()
		void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
		void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
		void releaseResources() override
		void paint (Graphics& g) override
		void resized() override
	private:
		MidiKeyboardState keyboardState;
		MidiMessageCollector midiCollector;
		Synthesiser synth;
		DroneUI droneUI;

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};



#endif  // DRONEMAINCOMPONENT_H_INCLUDED
