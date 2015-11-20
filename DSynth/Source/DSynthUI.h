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

#ifndef __JUCE_HEADER_40DD2A6950335F80__
#define __JUCE_HEADER_40DD2A6950335F80__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"

class MainComponent;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class DSynthUI  : public Component,
                  public SliderListener,
                  public ComboBoxListener,
                  public ButtonListener
{
public:
    //==============================================================================
    DSynthUI (MainComponent &_owner);
    ~DSynthUI();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    MainComponent &owner;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> oscFreqA;
    ScopedPointer<Slider> oscFreqR;
    ScopedPointer<Slider> oscFreq;
    ScopedPointer<Slider> oscLevelA;
    ScopedPointer<Slider> oscLevelR;
    ScopedPointer<Slider> noiseLevel;
    ScopedPointer<Slider> noiseLevelA;
    ScopedPointer<Slider> noiseLevelR;
    ScopedPointer<ComboBox> oscShape;
    ScopedPointer<ToggleButton> waveshapeBtn;
    ScopedPointer<ComboBox> distortionType;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DSynthUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_40DD2A6950335F80__
