/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 4.0.1

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_9FEDBF8A3F7FBFDC__
#define __JUCE_HEADER_9FEDBF8A3F7FBFDC__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
class Drone;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class DroneUI  : public Component,
                 public SliderListener,
                 public ButtonListener
{
public:
    //==============================================================================
    DroneUI (Drone &_drone,  MidiKeyboardState &_keyboardState);
    ~DroneUI();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    MidiKeyboardState &keyboardState;
    Drone &drone;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> offset1;
    ScopedPointer<ToggleButton> hold;
    ScopedPointer<MidiKeyboardComponent> keyboard;
    ScopedPointer<ToggleButton> shape1;
    ScopedPointer<Slider> offset2;
    ScopedPointer<Slider> offset3;
    ScopedPointer<Slider> offset4;
    ScopedPointer<Slider> offset5;
    ScopedPointer<Slider> offset6;
    ScopedPointer<Slider> offset7;
    ScopedPointer<Slider> offset8;
    ScopedPointer<ToggleButton> shape2;
    ScopedPointer<ToggleButton> shape3;
    ScopedPointer<ToggleButton> shape4;
    ScopedPointer<ToggleButton> shape5;
    ScopedPointer<ToggleButton> shape6;
    ScopedPointer<ToggleButton> shape7;
    ScopedPointer<ToggleButton> shape8;
    ScopedPointer<Slider> rSize;
    ScopedPointer<Slider> rDamp;
    ScopedPointer<Slider> rWet;
    ScopedPointer<Slider> rDry;
    ScopedPointer<Slider> rWidth;
    ScopedPointer<ToggleButton> rFreeze;
    ScopedPointer<Label> label;
    ScopedPointer<Label> label2;
    ScopedPointer<Label> label3;
    ScopedPointer<Label> label4;
    ScopedPointer<Label> label5;
    ScopedPointer<Label> label6;
    ScopedPointer<Slider> dLength;
    ScopedPointer<Slider> dFbk;
    ScopedPointer<Slider> dWet;
    ScopedPointer<Slider> dDry;
    ScopedPointer<Label> label7;
    ScopedPointer<Label> d;
    ScopedPointer<Label> label9;
    ScopedPointer<Label> label10;
    ScopedPointer<TextButton> dReset;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DroneUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_9FEDBF8A3F7FBFDC__
