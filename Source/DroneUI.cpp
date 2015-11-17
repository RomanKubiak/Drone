/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.2.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "Drone.h"
//[/Headers]

#include "DroneUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
DroneUI::DroneUI (Drone &_drone,  MidiKeyboardState &_keyboardState)
    : keyboardState(_keyboardState), drone(_drone)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (offset1 = new Slider ("1"));
    offset1->setRange (-50, 50, 0.05);
    offset1->setSliderStyle (Slider::LinearVertical);
    offset1->setTextBoxStyle (Slider::TextBoxBelow, false, 56, 16);
    offset1->addListener (this);

    addAndMakeVisible (hold = new ToggleButton ("new toggle button"));
    hold->setButtonText (TRANS("Hold"));
    hold->addListener (this);

    addAndMakeVisible (keyboard = new MidiKeyboardComponent (keyboardState, MidiKeyboardComponent::horizontalKeyboard));

    addAndMakeVisible (shape1 = new ToggleButton ("1"));
    shape1->setButtonText (TRANS("Saw"));
    shape1->addListener (this);

    addAndMakeVisible (offset2 = new Slider ("2"));
    offset2->setRange (-50, 50, 0.05);
    offset2->setSliderStyle (Slider::LinearVertical);
    offset2->setTextBoxStyle (Slider::TextBoxBelow, false, 56, 16);
    offset2->addListener (this);

    addAndMakeVisible (offset3 = new Slider ("3"));
    offset3->setRange (-50, 50, 0.05);
    offset3->setSliderStyle (Slider::LinearVertical);
    offset3->setTextBoxStyle (Slider::TextBoxBelow, false, 56, 16);
    offset3->addListener (this);

    addAndMakeVisible (offset4 = new Slider ("4"));
    offset4->setRange (-50, 50, 0.05);
    offset4->setSliderStyle (Slider::LinearVertical);
    offset4->setTextBoxStyle (Slider::TextBoxBelow, false, 56, 16);
    offset4->addListener (this);

    addAndMakeVisible (offset5 = new Slider ("5"));
    offset5->setRange (-50, 50, 0.05);
    offset5->setSliderStyle (Slider::LinearVertical);
    offset5->setTextBoxStyle (Slider::TextBoxBelow, false, 56, 16);
    offset5->addListener (this);

    addAndMakeVisible (offset6 = new Slider ("6"));
    offset6->setRange (-50, 50, 0.05);
    offset6->setSliderStyle (Slider::LinearVertical);
    offset6->setTextBoxStyle (Slider::TextBoxBelow, false, 56, 16);
    offset6->addListener (this);

    addAndMakeVisible (offset7 = new Slider ("7"));
    offset7->setRange (-50, 50, 0.05);
    offset7->setSliderStyle (Slider::LinearVertical);
    offset7->setTextBoxStyle (Slider::TextBoxBelow, false, 56, 16);
    offset7->addListener (this);

    addAndMakeVisible (offset8 = new Slider ("8"));
    offset8->setRange (-50, 50, 0.05);
    offset8->setSliderStyle (Slider::LinearVertical);
    offset8->setTextBoxStyle (Slider::TextBoxBelow, false, 56, 16);
    offset8->addListener (this);

    addAndMakeVisible (offset9 = new Slider ("9"));
    offset9->setRange (-50, 50, 0.05);
    offset9->setSliderStyle (Slider::LinearVertical);
    offset9->setTextBoxStyle (Slider::TextBoxBelow, false, 56, 16);
    offset9->addListener (this);

    addAndMakeVisible (shape2 = new ToggleButton ("2"));
    shape2->setButtonText (TRANS("Saw"));
    shape2->addListener (this);

    addAndMakeVisible (shape3 = new ToggleButton ("3"));
    shape3->setButtonText (TRANS("Saw"));
    shape3->addListener (this);

    addAndMakeVisible (shape4 = new ToggleButton ("4"));
    shape4->setButtonText (TRANS("Saw"));
    shape4->addListener (this);

    addAndMakeVisible (shape5 = new ToggleButton ("5"));
    shape5->setButtonText (TRANS("Saw"));
    shape5->addListener (this);

    addAndMakeVisible (shape6 = new ToggleButton ("6"));
    shape6->setButtonText (TRANS("Saw"));
    shape6->addListener (this);

    addAndMakeVisible (shape7 = new ToggleButton ("7"));
    shape7->setButtonText (TRANS("Saw"));
    shape7->addListener (this);

    addAndMakeVisible (shape8 = new ToggleButton ("8"));
    shape8->setButtonText (TRANS("Saw"));
    shape8->addListener (this);

    addAndMakeVisible (shape9 = new ToggleButton ("new toggle button"));
    shape9->setButtonText (TRANS("Saw"));
    shape9->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 600);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

DroneUI::~DroneUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    offset1 = nullptr;
    hold = nullptr;
    keyboard = nullptr;
    shape1 = nullptr;
    offset2 = nullptr;
    offset3 = nullptr;
    offset4 = nullptr;
    offset5 = nullptr;
    offset6 = nullptr;
    offset7 = nullptr;
    offset8 = nullptr;
    offset9 = nullptr;
    shape2 = nullptr;
    shape3 = nullptr;
    shape4 = nullptr;
    shape5 = nullptr;
    shape6 = nullptr;
    shape7 = nullptr;
    shape8 = nullptr;
    shape9 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void DroneUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void DroneUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    offset1->setBounds (proportionOfWidth (0.0000f), 0, proportionOfWidth (0.1000f), proportionOfHeight (0.8000f));
    hold->setBounds (proportionOfWidth (0.9200f), proportionOfHeight (0.8000f), proportionOfWidth (0.0800f), proportionOfHeight (0.0500f));
    keyboard->setBounds (0, proportionOfHeight (0.8500f), proportionOfWidth (1.0000f), proportionOfHeight (0.1500f));
    shape1->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.8000f), proportionOfWidth (0.1000f), proportionOfHeight (0.0500f));
    offset2->setBounds (proportionOfWidth (0.1000f), 0, proportionOfWidth (0.1000f), proportionOfHeight (0.8000f));
    offset3->setBounds (proportionOfWidth (0.2000f), 0, proportionOfWidth (0.1000f), proportionOfHeight (0.8000f));
    offset4->setBounds (proportionOfWidth (0.3000f), 0, proportionOfWidth (0.1000f), proportionOfHeight (0.8000f));
    offset5->setBounds (proportionOfWidth (0.4000f), 0, proportionOfWidth (0.1000f), proportionOfHeight (0.8000f));
    offset6->setBounds (proportionOfWidth (0.5000f), 0, proportionOfWidth (0.1000f), proportionOfHeight (0.8000f));
    offset7->setBounds (proportionOfWidth (0.6000f), 0, proportionOfWidth (0.1000f), proportionOfHeight (0.8000f));
    offset8->setBounds (proportionOfWidth (0.7000f), 0, proportionOfWidth (0.1000f), proportionOfHeight (0.8000f));
    offset9->setBounds (proportionOfWidth (0.8000f), 0, proportionOfWidth (0.1000f), proportionOfHeight (0.8000f));
    shape2->setBounds (proportionOfWidth (0.1000f), proportionOfHeight (0.8000f), proportionOfWidth (0.1000f), proportionOfHeight (0.0500f));
    shape3->setBounds (proportionOfWidth (0.2000f), proportionOfHeight (0.8000f), proportionOfWidth (0.1000f), proportionOfHeight (0.0500f));
    shape4->setBounds (proportionOfWidth (0.3000f), proportionOfHeight (0.8000f), proportionOfWidth (0.1000f), proportionOfHeight (0.0500f));
    shape5->setBounds (proportionOfWidth (0.4000f), proportionOfHeight (0.8000f), proportionOfWidth (0.1000f), proportionOfHeight (0.0500f));
    shape6->setBounds (proportionOfWidth (0.5000f), proportionOfHeight (0.8000f), proportionOfWidth (0.1000f), proportionOfHeight (0.0500f));
    shape7->setBounds (proportionOfWidth (0.6000f), proportionOfHeight (0.8000f), proportionOfWidth (0.1000f), proportionOfHeight (0.0500f));
    shape8->setBounds (proportionOfWidth (0.7000f), proportionOfHeight (0.8000f), proportionOfWidth (0.1000f), proportionOfHeight (0.0500f));
    shape9->setBounds (proportionOfWidth (0.8000f), proportionOfHeight (0.8000f), proportionOfWidth (0.1000f), proportionOfHeight (0.0500f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void DroneUI::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == offset1)
    {
        //[UserSliderCode_offset1] -- add your slider handling code here..
        //[/UserSliderCode_offset1]
    }
    else if (sliderThatWasMoved == offset2)
    {
        //[UserSliderCode_offset2] -- add your slider handling code here..
        //[/UserSliderCode_offset2]
    }
    else if (sliderThatWasMoved == offset3)
    {
        //[UserSliderCode_offset3] -- add your slider handling code here..
        //[/UserSliderCode_offset3]
    }
    else if (sliderThatWasMoved == offset4)
    {
        //[UserSliderCode_offset4] -- add your slider handling code here..
        //[/UserSliderCode_offset4]
    }
    else if (sliderThatWasMoved == offset5)
    {
        //[UserSliderCode_offset5] -- add your slider handling code here..
        //[/UserSliderCode_offset5]
    }
    else if (sliderThatWasMoved == offset6)
    {
        //[UserSliderCode_offset6] -- add your slider handling code here..
        //[/UserSliderCode_offset6]
    }
    else if (sliderThatWasMoved == offset7)
    {
        //[UserSliderCode_offset7] -- add your slider handling code here..
        //[/UserSliderCode_offset7]
    }
    else if (sliderThatWasMoved == offset8)
    {
        //[UserSliderCode_offset8] -- add your slider handling code here..
        //[/UserSliderCode_offset8]
    }
    else if (sliderThatWasMoved == offset9)
    {
        //[UserSliderCode_offset9] -- add your slider handling code here..
        //[/UserSliderCode_offset9]
    }

    //[UsersliderValueChanged_Post]
	drone.setOffset(0, sliderThatWasMoved->getName().getIntValue(), sliderThatWasMoved->getValue());
    //[/UsersliderValueChanged_Post]
}

void DroneUI::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == hold)
    {
        //[UserButtonCode_hold] -- add your button handler code here..
        drone.setHold(hold->getToggleState());
		return;
        //[/UserButtonCode_hold]
    }
    else if (buttonThatWasClicked == shape1)
    {
        //[UserButtonCode_shape1] -- add your button handler code here..
        //[/UserButtonCode_shape1]
    }
    else if (buttonThatWasClicked == shape2)
    {
        //[UserButtonCode_shape2] -- add your button handler code here..
        //[/UserButtonCode_shape2]
    }
    else if (buttonThatWasClicked == shape3)
    {
        //[UserButtonCode_shape3] -- add your button handler code here..
        //[/UserButtonCode_shape3]
    }
    else if (buttonThatWasClicked == shape4)
    {
        //[UserButtonCode_shape4] -- add your button handler code here..
        //[/UserButtonCode_shape4]
    }
    else if (buttonThatWasClicked == shape5)
    {
        //[UserButtonCode_shape5] -- add your button handler code here..
        //[/UserButtonCode_shape5]
    }
    else if (buttonThatWasClicked == shape6)
    {
        //[UserButtonCode_shape6] -- add your button handler code here..
        //[/UserButtonCode_shape6]
    }
    else if (buttonThatWasClicked == shape7)
    {
        //[UserButtonCode_shape7] -- add your button handler code here..
        //[/UserButtonCode_shape7]
    }
    else if (buttonThatWasClicked == shape8)
    {
        //[UserButtonCode_shape8] -- add your button handler code here..
        //[/UserButtonCode_shape8]
    }
    else if (buttonThatWasClicked == shape9)
    {
        //[UserButtonCode_shape9] -- add your button handler code here..
        //[/UserButtonCode_shape9]
    }

    //[UserbuttonClicked_Post]
	drone.setShape(0,buttonThatWasClicked->getName().getIntValue(), buttonThatWasClicked->getToggleState());
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="DroneUI" componentName=""
                 parentClasses="public Component" constructorParams="Drone &amp;_drone,  MidiKeyboardState &amp;_keyboardState"
                 variableInitialisers="keyboardState(_keyboardState), drone(_drone)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="600">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="1" id="428397bc676bcef0" memberName="offset1" virtualName=""
          explicitFocusOrder="0" pos="0% 0 10% 80%" min="-50" max="50"
          int="0.050000000000000003" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1"/>
  <TOGGLEBUTTON name="new toggle button" id="79497acca0c75b76" memberName="hold"
                virtualName="" explicitFocusOrder="0" pos="92% 80% 8% 5%" buttonText="Hold"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <GENERICCOMPONENT name="" id="6ec56c10c2de0986" memberName="keyboard" virtualName=""
                    explicitFocusOrder="0" pos="0 85% 100% 15%" class="MidiKeyboardComponent"
                    params="keyboardState, MidiKeyboardComponent::horizontalKeyboard"/>
  <TOGGLEBUTTON name="1" id="e127883564010c25" memberName="shape1" virtualName=""
                explicitFocusOrder="0" pos="0% 80% 10% 5%" buttonText="Saw" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <SLIDER name="2" id="5a86372cba62bec4" memberName="offset2" virtualName=""
          explicitFocusOrder="0" pos="10% 0 10% 80%" min="-50" max="50"
          int="0.050000000000000003" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="3" id="9835de7c44af05f3" memberName="offset3" virtualName=""
          explicitFocusOrder="0" pos="20% 0 10% 80%" min="-50" max="50"
          int="0.050000000000000003" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="4" id="d9d578504472a0a3" memberName="offset4" virtualName=""
          explicitFocusOrder="0" pos="30% 0 10% 80%" min="-50" max="50"
          int="0.050000000000000003" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="5" id="1bb761a4ac6769c5" memberName="offset5" virtualName=""
          explicitFocusOrder="0" pos="40% 0 10% 80%" min="-50" max="50"
          int="0.050000000000000003" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="6" id="6737513c7240acc6" memberName="offset6" virtualName=""
          explicitFocusOrder="0" pos="50% 0 10% 80%" min="-50" max="50"
          int="0.050000000000000003" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="7" id="fa4726b4261b4911" memberName="offset7" virtualName=""
          explicitFocusOrder="0" pos="60% 0 10% 80%" min="-50" max="50"
          int="0.050000000000000003" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="8" id="c1116d514ce09d7" memberName="offset8" virtualName=""
          explicitFocusOrder="0" pos="70% 0 10% 80%" min="-50" max="50"
          int="0.050000000000000003" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="9" id="b49fc92991813612" memberName="offset9" virtualName=""
          explicitFocusOrder="0" pos="80% 0 10% 80%" min="-50" max="50"
          int="0.050000000000000003" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1"/>
  <TOGGLEBUTTON name="2" id="359f79f7871da524" memberName="shape2" virtualName=""
                explicitFocusOrder="0" pos="10% 80% 10% 5%" buttonText="Saw"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="3" id="699f26046c54f72d" memberName="shape3" virtualName=""
                explicitFocusOrder="0" pos="20% 80% 10% 5%" buttonText="Saw"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="4" id="c0d5d7a3fef56db6" memberName="shape4" virtualName=""
                explicitFocusOrder="0" pos="30% 80% 10% 5%" buttonText="Saw"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="5" id="a978c58648d74d53" memberName="shape5" virtualName=""
                explicitFocusOrder="0" pos="40% 80% 10% 5%" buttonText="Saw"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="6" id="2ade7647616c154" memberName="shape6" virtualName=""
                explicitFocusOrder="0" pos="50% 80% 10% 5%" buttonText="Saw"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="7" id="e0dff90d160d234b" memberName="shape7" virtualName=""
                explicitFocusOrder="0" pos="60% 80% 10% 5%" buttonText="Saw"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="8" id="97e71abe9418b6ca" memberName="shape8" virtualName=""
                explicitFocusOrder="0" pos="70% 80% 10% 5%" buttonText="Saw"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="15aaa2b6bd3ddd71" memberName="shape9"
                virtualName="" explicitFocusOrder="0" pos="80% 80% 10% 5%" buttonText="Saw"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
