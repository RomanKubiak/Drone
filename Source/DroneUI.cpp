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

    addAndMakeVisible (rSize = new Slider ("rSize"));
    rSize->setRange (0, 255, 1);
    rSize->setSliderStyle (Slider::RotaryVerticalDrag);
    rSize->setTextBoxStyle (Slider::TextBoxBelow, false, 32, 16);
    rSize->addListener (this);

    addAndMakeVisible (rDamp = new Slider ("rDamp"));
    rDamp->setRange (0, 255, 1);
    rDamp->setSliderStyle (Slider::RotaryVerticalDrag);
    rDamp->setTextBoxStyle (Slider::TextBoxBelow, false, 32, 16);
    rDamp->addListener (this);

    addAndMakeVisible (rWet = new Slider ("rWet"));
    rWet->setRange (0, 255, 1);
    rWet->setSliderStyle (Slider::RotaryVerticalDrag);
    rWet->setTextBoxStyle (Slider::TextBoxBelow, false, 32, 16);
    rWet->addListener (this);

    addAndMakeVisible (rDry = new Slider ("rDry"));
    rDry->setRange (0, 255, 1);
    rDry->setSliderStyle (Slider::RotaryVerticalDrag);
    rDry->setTextBoxStyle (Slider::TextBoxBelow, false, 32, 16);
    rDry->addListener (this);

    addAndMakeVisible (rWidth = new Slider ("rWidth"));
    rWidth->setRange (0, 255, 1);
    rWidth->setSliderStyle (Slider::RotaryVerticalDrag);
    rWidth->setTextBoxStyle (Slider::TextBoxBelow, false, 32, 16);
    rWidth->addListener (this);

    addAndMakeVisible (rFreeze = new ToggleButton ("rFreeze"));
    rFreeze->setButtonText (String::empty);
    rFreeze->addListener (this);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Size")));
    label->setFont (Font (14.00f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Damp")));
    label2->setFont (Font (14.00f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("Wet")));
    label3->setFont (Font (14.00f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label4 = new Label ("new label",
                                           TRANS("Dry")));
    label4->setFont (Font (14.00f, Font::plain));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label5 = new Label ("new label",
                                           TRANS("Width")));
    label5->setFont (Font (14.00f, Font::plain));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label6 = new Label ("new label",
                                           TRANS("Freeze")));
    label6->setFont (Font (14.00f, Font::plain));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (dLength = new Slider ("dLength"));
    dLength->setRange (0, 10, 0.05);
    dLength->setSliderStyle (Slider::RotaryVerticalDrag);
    dLength->setTextBoxStyle (Slider::TextBoxBelow, false, 32, 16);
    dLength->addListener (this);

    addAndMakeVisible (dFbk = new Slider ("dFbk"));
    dFbk->setRange (0, 255, 1);
    dFbk->setSliderStyle (Slider::RotaryVerticalDrag);
    dFbk->setTextBoxStyle (Slider::TextBoxBelow, false, 32, 16);
    dFbk->addListener (this);

    addAndMakeVisible (dWet = new Slider ("dWet"));
    dWet->setRange (0, 255, 1);
    dWet->setSliderStyle (Slider::RotaryVerticalDrag);
    dWet->setTextBoxStyle (Slider::TextBoxBelow, false, 32, 16);
    dWet->addListener (this);

    addAndMakeVisible (dDry = new Slider ("dDry"));
    dDry->setRange (0, 255, 1);
    dDry->setSliderStyle (Slider::RotaryVerticalDrag);
    dDry->setTextBoxStyle (Slider::TextBoxBelow, false, 32, 16);
    dDry->addListener (this);

    addAndMakeVisible (label7 = new Label ("new label",
                                           TRANS("Length")));
    label7->setFont (Font (14.00f, Font::plain));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d = new Label ("new label",
                                      TRANS("Wet")));
    d->setFont (Font (14.00f, Font::plain));
    d->setJustificationType (Justification::centredLeft);
    d->setEditable (false, false, false);
    d->setColour (TextEditor::textColourId, Colours::black);
    d->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label9 = new Label ("new label",
                                           TRANS("Dry")));
    label9->setFont (Font (14.00f, Font::plain));
    label9->setJustificationType (Justification::centredLeft);
    label9->setEditable (false, false, false);
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label10 = new Label ("new label",
                                            TRANS("Feedback")));
    label10->setFont (Font (14.00f, Font::plain));
    label10->setJustificationType (Justification::centredLeft);
    label10->setEditable (false, false, false);
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (dReset = new TextButton ("dReset"));
    dReset->setButtonText (TRANS("RST"));
    dReset->addListener (this);


    //[UserPreSize]
    rWet->setValue(0,sendNotification);
    rDry->setValue(255,sendNotification);
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
    shape2 = nullptr;
    shape3 = nullptr;
    shape4 = nullptr;
    shape5 = nullptr;
    shape6 = nullptr;
    shape7 = nullptr;
    shape8 = nullptr;
    rSize = nullptr;
    rDamp = nullptr;
    rWet = nullptr;
    rDry = nullptr;
    rWidth = nullptr;
    rFreeze = nullptr;
    label = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    label4 = nullptr;
    label5 = nullptr;
    label6 = nullptr;
    dLength = nullptr;
    dFbk = nullptr;
    dWet = nullptr;
    dDry = nullptr;
    label7 = nullptr;
    d = nullptr;
    label9 = nullptr;
    label10 = nullptr;
    dReset = nullptr;


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
    shape2->setBounds (proportionOfWidth (0.1000f), proportionOfHeight (0.8000f), proportionOfWidth (0.1000f), proportionOfHeight (0.0500f));
    shape3->setBounds (proportionOfWidth (0.2000f), proportionOfHeight (0.8000f), proportionOfWidth (0.1000f), proportionOfHeight (0.0500f));
    shape4->setBounds (proportionOfWidth (0.3000f), proportionOfHeight (0.8000f), proportionOfWidth (0.1000f), proportionOfHeight (0.0500f));
    shape5->setBounds (proportionOfWidth (0.4000f), proportionOfHeight (0.8000f), proportionOfWidth (0.1000f), proportionOfHeight (0.0500f));
    shape6->setBounds (proportionOfWidth (0.5000f), proportionOfHeight (0.8000f), proportionOfWidth (0.1000f), proportionOfHeight (0.0500f));
    shape7->setBounds (proportionOfWidth (0.6000f), proportionOfHeight (0.8000f), proportionOfWidth (0.1000f), proportionOfHeight (0.0500f));
    shape8->setBounds (proportionOfWidth (0.7000f), proportionOfHeight (0.8000f), proportionOfWidth (0.1000f), proportionOfHeight (0.0500f));
    rSize->setBounds (proportionOfWidth (0.8000f), 32, proportionOfWidth (0.0533f), 48);
    rDamp->setBounds (proportionOfWidth (0.8800f), 32, proportionOfWidth (0.0533f), 48);
    rWet->setBounds (proportionOfWidth (0.8000f), 96, proportionOfWidth (0.0533f), 48);
    rDry->setBounds (proportionOfWidth (0.8800f), 96, proportionOfWidth (0.0533f), 48);
    rWidth->setBounds (proportionOfWidth (0.8000f), 160, proportionOfWidth (0.0533f), 48);
    rFreeze->setBounds (proportionOfWidth (0.8800f), 168, proportionOfWidth (0.0400f), 24);
    label->setBounds (proportionOfWidth (0.8000f), 16, proportionOfWidth (0.0800f), 16);
    label2->setBounds (proportionOfWidth (0.8800f), 16, 48, 16);
    label3->setBounds (proportionOfWidth (0.8000f), 80, proportionOfWidth (0.0800f), 16);
    label4->setBounds (proportionOfWidth (0.8800f), 80, proportionOfWidth (0.0800f), 16);
    label5->setBounds (proportionOfWidth (0.8000f), 144, proportionOfWidth (0.0800f), 16);
    label6->setBounds (proportionOfWidth (0.8800f), 144, 48, 16);
    dLength->setBounds (proportionOfWidth (0.8000f), 264, proportionOfWidth (0.0533f), 48);
    dFbk->setBounds (proportionOfWidth (0.8800f), 264, proportionOfWidth (0.0533f), 48);
    dWet->setBounds (proportionOfWidth (0.8000f), 336, proportionOfWidth (0.0533f), 48);
    dDry->setBounds (proportionOfWidth (0.8800f), 336, proportionOfWidth (0.0533f), 48);
    label7->setBounds (proportionOfWidth (0.8000f), 248, proportionOfWidth (0.0800f), 16);
    d->setBounds (proportionOfWidth (0.8000f), 320, proportionOfWidth (0.0800f), 16);
    label9->setBounds (proportionOfWidth (0.8800f), 320, proportionOfWidth (0.0800f), 16);
    label10->setBounds (proportionOfWidth (0.8800f), 248, proportionOfWidth (0.0800f), 16);
    dReset->setBounds (proportionOfWidth (0.8800f), 400, proportionOfWidth (0.0600f), 32);
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
    else if (sliderThatWasMoved == rSize)
    {
        //[UserSliderCode_rSize] -- add your slider handling code here..
        //[/UserSliderCode_rSize]
    }
    else if (sliderThatWasMoved == rDamp)
    {
        //[UserSliderCode_rDamp] -- add your slider handling code here..
        //[/UserSliderCode_rDamp]
    }
    else if (sliderThatWasMoved == rWet)
    {
        //[UserSliderCode_rWet] -- add your slider handling code here..
        //[/UserSliderCode_rWet]
    }
    else if (sliderThatWasMoved == rDry)
    {
        //[UserSliderCode_rDry] -- add your slider handling code here..
        //[/UserSliderCode_rDry]
    }
    else if (sliderThatWasMoved == rWidth)
    {
        //[UserSliderCode_rWidth] -- add your slider handling code here..
        //[/UserSliderCode_rWidth]
    }
    else if (sliderThatWasMoved == dLength)
    {
        //[UserSliderCode_dLength] -- add your slider handling code here..
        //[/UserSliderCode_dLength]
    }
    else if (sliderThatWasMoved == dFbk)
    {
        //[UserSliderCode_dFbk] -- add your slider handling code here..
        //[/UserSliderCode_dFbk]
    }
    else if (sliderThatWasMoved == dWet)
    {
        //[UserSliderCode_dWet] -- add your slider handling code here..
        //[/UserSliderCode_dWet]
    }
    else if (sliderThatWasMoved == dDry)
    {
        //[UserSliderCode_dDry] -- add your slider handling code here..
        //[/UserSliderCode_dDry]
    }

    //[UsersliderValueChanged_Post]
    if (sliderThatWasMoved->getName().startsWith("r"))
    {
        drone.setReverb(rSize->getValue(), rDamp->getValue(), rWet->getValue(), rDry->getValue(), rWidth->getValue(), rFreeze->getToggleState());
    }
    else if (sliderThatWasMoved->getName().startsWith("d"))
    {
        drone.setDelay(dLength->getValue(), dWet->getValue(), dDry->getValue(), dFbk->getValue());
    }
    else
    {
        drone.setOffset(0, sliderThatWasMoved->getName().getIntValue()-1, sliderThatWasMoved->getValue());
    }
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
    else if (buttonThatWasClicked == rFreeze)
    {
        //[UserButtonCode_rFreeze] -- add your button handler code here..
        drone.setReverb(rSize->getValue(), rDamp->getValue(), rWet->getValue(), rDry->getValue(), rWidth->getValue(), rFreeze->getToggleState());
        //[/UserButtonCode_rFreeze]
    }
    else if (buttonThatWasClicked == dReset)
    {
        //[UserButtonCode_dReset] -- add your button handler code here..
        drone.resetDelay();
        //[/UserButtonCode_dReset]
    }

    //[UserbuttonClicked_Post]
	drone.setShape(0,buttonThatWasClicked->getName().getIntValue()-1, buttonThatWasClicked->getToggleState());
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
          int="0.050000000000000002776" style="LinearVertical" textBoxPos="TextBoxBelow"
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
          int="0.050000000000000002776" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="3" id="9835de7c44af05f3" memberName="offset3" virtualName=""
          explicitFocusOrder="0" pos="20% 0 10% 80%" min="-50" max="50"
          int="0.050000000000000002776" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="4" id="d9d578504472a0a3" memberName="offset4" virtualName=""
          explicitFocusOrder="0" pos="30% 0 10% 80%" min="-50" max="50"
          int="0.050000000000000002776" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="5" id="1bb761a4ac6769c5" memberName="offset5" virtualName=""
          explicitFocusOrder="0" pos="40% 0 10% 80%" min="-50" max="50"
          int="0.050000000000000002776" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="6" id="6737513c7240acc6" memberName="offset6" virtualName=""
          explicitFocusOrder="0" pos="50% 0 10% 80%" min="-50" max="50"
          int="0.050000000000000002776" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="7" id="fa4726b4261b4911" memberName="offset7" virtualName=""
          explicitFocusOrder="0" pos="60% 0 10% 80%" min="-50" max="50"
          int="0.050000000000000002776" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="56" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="8" id="c1116d514ce09d7" memberName="offset8" virtualName=""
          explicitFocusOrder="0" pos="70% 0 10% 80%" min="-50" max="50"
          int="0.050000000000000002776" style="LinearVertical" textBoxPos="TextBoxBelow"
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
  <SLIDER name="rSize" id="9fd7d93335c70ab8" memberName="rSize" virtualName=""
          explicitFocusOrder="0" pos="80% 32 5.333% 48" min="0" max="255"
          int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="32" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="rDamp" id="ebe0be3241cea246" memberName="rDamp" virtualName=""
          explicitFocusOrder="0" pos="88% 32 5.333% 48" min="0" max="255"
          int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="32" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="rWet" id="2b855724a35f9e76" memberName="rWet" virtualName=""
          explicitFocusOrder="0" pos="80% 96 5.333% 48" min="0" max="255"
          int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="32" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="rDry" id="e6854687379bed26" memberName="rDry" virtualName=""
          explicitFocusOrder="0" pos="88% 96 5.333% 48" min="0" max="255"
          int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="32" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="rWidth" id="1116aacb25c16ae0" memberName="rWidth" virtualName=""
          explicitFocusOrder="0" pos="80% 160 5.333% 48" min="0" max="255"
          int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="32" textBoxHeight="16" skewFactor="1"/>
  <TOGGLEBUTTON name="rFreeze" id="fef06258f770a184" memberName="rFreeze" virtualName=""
                explicitFocusOrder="0" pos="88% 168 4% 24" buttonText="" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="d25b56ed3de3f3ba" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="80% 16 8% 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Size" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="bd9203d410fa9830" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="88% 16 48 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Damp" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="a68e6170aa740fb0" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="80% 80 8% 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Wet" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="1f8a3fe24d3ffa54" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="88% 80 8% 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Dry" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="f7397ea9510b8864" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="80% 144 8% 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Width" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="a5f9df75880b9233" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="88% 144 48 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Freeze" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="dLength" id="d77a5182647bb086" memberName="dLength" virtualName=""
          explicitFocusOrder="0" pos="80% 264 5.333% 48" min="0" max="10"
          int="0.050000000000000002776" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="32" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="dFbk" id="24ad4df0bd1edde" memberName="dFbk" virtualName=""
          explicitFocusOrder="0" pos="88% 264 5.333% 48" min="0" max="255"
          int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="32" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="dWet" id="46d9abeb252f6224" memberName="dWet" virtualName=""
          explicitFocusOrder="0" pos="80% 336 5.333% 48" min="0" max="255"
          int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="32" textBoxHeight="16" skewFactor="1"/>
  <SLIDER name="dDry" id="512f0ea80bdbc8fe" memberName="dDry" virtualName=""
          explicitFocusOrder="0" pos="88% 336 5.333% 48" min="0" max="255"
          int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="32" textBoxHeight="16" skewFactor="1"/>
  <LABEL name="new label" id="67ee98d13e14a9e0" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="80% 248 8% 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Length" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="37d2a342f3123f9e" memberName="d" virtualName=""
         explicitFocusOrder="0" pos="80% 320 8% 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Wet" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="f6394f967cbac542" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="88% 320 8% 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Dry" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="40042a110e7d3c1f" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="88% 248 8% 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Feedback" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14"
         bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="dReset" id="86260a15e83f7a09" memberName="dReset" virtualName=""
              explicitFocusOrder="0" pos="88% 400 6% 32" buttonText="RST" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
