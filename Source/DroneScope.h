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

#ifndef __JUCE_HEADER_DEE330CA5492D45C__
#define __JUCE_HEADER_DEE330CA5492D45C__

//[Headers]     -- You can add your own extra header files here --
#include "dRowAudio_AudioOscilloscope.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class DroneScope  : public Component
{
public:
    //==============================================================================
    DroneScope ();
    ~DroneScope();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //AudioOscilloscope& getOscilloscope() { return (oscilloscope); }
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void mouseWheelMove (const MouseEvent& e, const MouseWheelDetails& wheel);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //AudioOscilloscope oscilloscope;
    float vZoom,hZoom;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DroneScope)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_DEE330CA5492D45C__
