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
	bufferToFill.buffer->applyGain(0.25f);
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

Component* createMainContentComponent()     { return new Drone(); }

#endif  // MAINCOMPONENT_H_INCLUDED
