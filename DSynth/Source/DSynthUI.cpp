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
//[/Headers]

#include "DSynthUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
#include "MainComponent.h"
//[/MiscUserDefs]

//==============================================================================
DSynthUI::DSynthUI (MainComponent &_owner)
    : owner(_owner)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (oscFreqA = new Slider ("oscFreqA"));
    oscFreqA->setRange (0.0001, 1, 0.0001);
    oscFreqA->setSliderStyle (Slider::RotaryVerticalDrag);
    oscFreqA->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    oscFreqA->addListener (this);

    addAndMakeVisible (oscFreqR = new Slider ("oscFreqR"));
    oscFreqR->setRange (0.01, 1, 0.01);
    oscFreqR->setSliderStyle (Slider::RotaryVerticalDrag);
    oscFreqR->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    oscFreqR->addListener (this);

    addAndMakeVisible (oscFreq = new Slider ("oscFreq"));
    oscFreq->setRange (1, 150, 0.5);
    oscFreq->setSliderStyle (Slider::RotaryVerticalDrag);
    oscFreq->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    oscFreq->setColour (Slider::thumbColourId, Colour (0xffffbbbb));
    oscFreq->setColour (Slider::rotarySliderFillColourId, Colour (0x7fff0000));
    oscFreq->setColour (Slider::textBoxHighlightColourId, Colour (0x40ee1111));
    oscFreq->addListener (this);

    addAndMakeVisible (oscLevelA = new Slider ("oscLevelA"));
    oscLevelA->setRange (0.0001, 1, 0.0001);
    oscLevelA->setSliderStyle (Slider::RotaryVerticalDrag);
    oscLevelA->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    oscLevelA->addListener (this);

    addAndMakeVisible (oscLevelR = new Slider ("oscLevelR"));
    oscLevelR->setRange (0.0001, 1, 0.0001);
    oscLevelR->setSliderStyle (Slider::RotaryVerticalDrag);
    oscLevelR->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    oscLevelR->addListener (this);

    addAndMakeVisible (noiseLevel = new Slider ("noiseLevel"));
    noiseLevel->setRange (0.0001, 1, 0.0001);
    noiseLevel->setSliderStyle (Slider::RotaryVerticalDrag);
    noiseLevel->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    noiseLevel->setColour (Slider::thumbColourId, Colour (0xffffbbbb));
    noiseLevel->setColour (Slider::rotarySliderFillColourId, Colour (0x7fff0000));
    noiseLevel->setColour (Slider::textBoxHighlightColourId, Colour (0x40ee1111));
    noiseLevel->addListener (this);

    addAndMakeVisible (noiseLevelA = new Slider ("noiseLevelA"));
    noiseLevelA->setRange (0.0001, 1, 0.0001);
    noiseLevelA->setSliderStyle (Slider::RotaryVerticalDrag);
    noiseLevelA->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    noiseLevelA->addListener (this);

    addAndMakeVisible (noiseLevelR = new Slider ("noiseLevelR"));
    noiseLevelR->setRange (0.0001, 1, 0.0001);
    noiseLevelR->setSliderStyle (Slider::RotaryVerticalDrag);
    noiseLevelR->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    noiseLevelR->addListener (this);

    addAndMakeVisible (oscShape = new ComboBox ("oscShape"));
    oscShape->setTooltip (TRANS("Sin\n"
    "Saw\n"
    "Square"));
    oscShape->setEditableText (false);
    oscShape->setJustificationType (Justification::centredLeft);
    oscShape->setTextWhenNothingSelected (TRANS("Sin"));
    oscShape->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    oscShape->addItem (TRANS("Sin"), 1);
    oscShape->addItem (TRANS("Saw"), 2);
    oscShape->addItem (TRANS("Square"), 3);
    oscShape->addItem (TRANS("Triangle"), 4);
    oscShape->addListener (this);

    addAndMakeVisible (waveshapeBtn = new ToggleButton ("waveshapeBtn"));
    waveshapeBtn->setButtonText (TRANS("Waveshape"));
    waveshapeBtn->addListener (this);

    addAndMakeVisible (distortionType = new ComboBox ("distortionType"));
    distortionType->setTooltip (TRANS("Sin\n"
    "Saw\n"
    "Square"));
    distortionType->setEditableText (false);
    distortionType->setJustificationType (Justification::centredLeft);
    distortionType->setTextWhenNothingSelected (TRANS("None"));
    distortionType->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    distortionType->addItem (TRANS("Hard Clipping"), 1);
    distortionType->addItem (TRANS("Soft Clipping"), 2);
    distortionType->addItem (TRANS("Soft Clipping EXP"), 3);
    distortionType->addItem (TRANS("Full Wave Rect"), 4);
    distortionType->addItem (TRANS("Half Wave Rect"), 5);
    distortionType->addItem (TRANS("None"), 6);
    distortionType->addListener (this);

    addAndMakeVisible (noiseCutoff = new Slider ("noiseCutoff"));
    noiseCutoff->setRange (0.0001, 1, 0.0001);
    noiseCutoff->setSliderStyle (Slider::RotaryVerticalDrag);
    noiseCutoff->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    noiseCutoff->setColour (Slider::thumbColourId, Colour (0xffbbffbc));
    noiseCutoff->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff17));
    noiseCutoff->addListener (this);

    addAndMakeVisible (noiseResonance = new Slider ("noiseLevelA"));
    noiseResonance->setRange (0, 100, 1);
    noiseResonance->setSliderStyle (Slider::RotaryVerticalDrag);
    noiseResonance->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    noiseResonance->setColour (Slider::rotarySliderFillColourId, Colour (0x7f008102));
    noiseResonance->addListener (this);


    //[UserPreSize]
    noiseLevelA->setValue(0.0001, sendNotification);
    oscFreq->setValue (55.0f);
    oscShape->setSelectedId(1, sendNotification);
    distortionType->setSelectedId(3, sendNotification);
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

DSynthUI::~DSynthUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    oscFreqA = nullptr;
    oscFreqR = nullptr;
    oscFreq = nullptr;
    oscLevelA = nullptr;
    oscLevelR = nullptr;
    noiseLevel = nullptr;
    noiseLevelA = nullptr;
    noiseLevelR = nullptr;
    oscShape = nullptr;
    waveshapeBtn = nullptr;
    distortionType = nullptr;
    noiseCutoff = nullptr;
    noiseResonance = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void DSynthUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void DSynthUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    oscFreqA->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.0000f), proportionOfWidth (0.1000f), proportionOfHeight (0.2000f));
    oscFreqR->setBounds (proportionOfWidth (0.1000f), proportionOfHeight (0.0000f), proportionOfWidth (0.1000f), proportionOfHeight (0.2000f));
    oscFreq->setBounds (proportionOfWidth (0.2000f), proportionOfHeight (0.0000f), proportionOfWidth (0.1000f), proportionOfHeight (0.2000f));
    oscLevelA->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.2000f), proportionOfWidth (0.1000f), proportionOfHeight (0.2000f));
    oscLevelR->setBounds (proportionOfWidth (0.1000f), proportionOfHeight (0.2000f), proportionOfWidth (0.1000f), proportionOfHeight (0.2000f));
    noiseLevel->setBounds (proportionOfWidth (0.2000f), proportionOfHeight (0.5000f), proportionOfWidth (0.1000f), proportionOfHeight (0.2000f));
    noiseLevelA->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.5000f), proportionOfWidth (0.1000f), proportionOfHeight (0.2000f));
    noiseLevelR->setBounds (proportionOfWidth (0.1000f), proportionOfHeight (0.5000f), proportionOfWidth (0.1000f), proportionOfHeight (0.2000f));
    oscShape->setBounds (proportionOfWidth (0.3200f), proportionOfHeight (0.1000f), proportionOfWidth (0.2000f), proportionOfHeight (0.0500f));
    waveshapeBtn->setBounds (proportionOfWidth (0.3200f), proportionOfHeight (0.1500f), proportionOfWidth (0.2000f), proportionOfHeight (0.0500f));
    distortionType->setBounds (proportionOfWidth (0.3200f), proportionOfHeight (0.0400f), proportionOfWidth (0.2000f), proportionOfHeight (0.0500f));
    noiseCutoff->setBounds (proportionOfWidth (0.3333f), proportionOfHeight (0.5000f), proportionOfWidth (0.1000f), proportionOfHeight (0.2000f));
    noiseResonance->setBounds (proportionOfWidth (0.4400f), proportionOfHeight (0.5000f), proportionOfWidth (0.1000f), proportionOfHeight (0.2000f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void DSynthUI::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == oscFreqA)
    {
        //[UserSliderCode_oscFreqA] -- add your slider handling code here..
        owner.setOscFreqAR(oscFreqA->getValue(), oscFreqR->getValue());
        //[/UserSliderCode_oscFreqA]
    }
    else if (sliderThatWasMoved == oscFreqR)
    {
        //[UserSliderCode_oscFreqR] -- add your slider handling code here..
        owner.setOscFreqAR(oscFreqA->getValue(), oscFreqR->getValue());
        //[/UserSliderCode_oscFreqR]
    }
    else if (sliderThatWasMoved == oscFreq)
    {
        //[UserSliderCode_oscFreq] -- add your slider handling code here..
        owner.setOscFreq(oscFreq->getValue());
        //[/UserSliderCode_oscFreq]
    }
    else if (sliderThatWasMoved == oscLevelA)
    {
        //[UserSliderCode_oscLevelA] -- add your slider handling code here..
        owner.setOscFreqAR(oscLevelA->getValue(), oscLevelR->getValue());
        //[/UserSliderCode_oscLevelA]
    }
    else if (sliderThatWasMoved == oscLevelR)
    {
        //[UserSliderCode_oscLevelR] -- add your slider handling code here..
        owner.setOscFreqAR(oscLevelA->getValue(), oscLevelR->getValue());
        //[/UserSliderCode_oscLevelR]
    }
    else if (sliderThatWasMoved == noiseLevel)
    {
        //[UserSliderCode_noiseLevel] -- add your slider handling code here..
        owner.setNoiseLevel(noiseLevel->getValue());
        //[/UserSliderCode_noiseLevel]
    }
    else if (sliderThatWasMoved == noiseLevelA)
    {
        //[UserSliderCode_noiseLevelA] -- add your slider handling code here..
        owner.setNoiseLevelAR(noiseLevelA->getValue(), noiseLevelR->getValue());
        //[/UserSliderCode_noiseLevelA]
    }
    else if (sliderThatWasMoved == noiseLevelR)
    {
        //[UserSliderCode_noiseLevelR] -- add your slider handling code here..
        owner.setNoiseLevelAR(noiseLevelA->getValue(), noiseLevelR->getValue());
        //[/UserSliderCode_noiseLevelR]
    }
    else if (sliderThatWasMoved == noiseCutoff)
    {
        //[UserSliderCode_noiseCutoff] -- add your slider handling code here..
        owner.setNoiseFilter(noiseCutoff->getValue(), noiseResonance->getValue());
        //[/UserSliderCode_noiseCutoff]
    }
    else if (sliderThatWasMoved == noiseResonance)
    {
        //[UserSliderCode_noiseResonance] -- add your slider handling code here..
        owner.setNoiseFilter(noiseCutoff->getValue(), noiseResonance->getValue());
        //[/UserSliderCode_noiseResonance]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void DSynthUI::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == oscShape)
    {
        //[UserComboBoxCode_oscShape] -- add your combo box handling code here..
        owner.setOscShape(oscShape->getSelectedItemIndex());
        //[/UserComboBoxCode_oscShape]
    }
    else if (comboBoxThatHasChanged == distortionType)
    {
        //[UserComboBoxCode_distortionType] -- add your combo box handling code here..
        owner.setDistortionType(distortionType->getSelectedItemIndex());
        //[/UserComboBoxCode_distortionType]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void DSynthUI::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == waveshapeBtn)
    {
        //[UserButtonCode_waveshapeBtn] -- add your button handler code here..
        owner.setWaveshape(buttonThatWasClicked->getToggleState());
        //[/UserButtonCode_waveshapeBtn]
    }

    //[UserbuttonClicked_Post]
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

<JUCER_COMPONENT documentType="Component" className="DSynthUI" componentName=""
                 parentClasses="public Component" constructorParams="MainComponent &amp;_owner"
                 variableInitialisers="owner(_owner)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="oscFreqA" id="4fd78b12fae831f9" memberName="oscFreqA" virtualName=""
          explicitFocusOrder="0" pos="0% 0% 10% 20%" min="0.00010000000000000000479"
          max="1" int="0.00010000000000000000479" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="oscFreqR" id="65a6e4601ada042d" memberName="oscFreqR" virtualName=""
          explicitFocusOrder="0" pos="10% 0% 10% 20%" min="0.010000000000000000208"
          max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="oscFreq" id="509daed58887dcac" memberName="oscFreq" virtualName=""
          explicitFocusOrder="0" pos="20% 0% 10% 20%" thumbcol="ffffbbbb"
          rotarysliderfill="7fff0000" textboxhighlight="40ee1111" min="1"
          max="150" int="0.5" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="oscLevelA" id="aed3b24e406f1a3d" memberName="oscLevelA"
          virtualName="" explicitFocusOrder="0" pos="0% 20% 10% 20%" min="0.00010000000000000000479"
          max="1" int="0.00010000000000000000479" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="oscLevelR" id="6d9827f3f0f0cef0" memberName="oscLevelR"
          virtualName="" explicitFocusOrder="0" pos="10% 20% 10% 20%" min="0.00010000000000000000479"
          max="1" int="0.00010000000000000000479" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="noiseLevel" id="c39ea9e4297a712e" memberName="noiseLevel"
          virtualName="" explicitFocusOrder="0" pos="20% 50% 10% 20%" thumbcol="ffffbbbb"
          rotarysliderfill="7fff0000" textboxhighlight="40ee1111" min="0.00010000000000000000479"
          max="1" int="0.00010000000000000000479" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="noiseLevelA" id="8f6107f1eaf16bac" memberName="noiseLevelA"
          virtualName="" explicitFocusOrder="0" pos="0% 50% 10% 20%" min="0.00010000000000000000479"
          max="1" int="0.00010000000000000000479" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="noiseLevelR" id="39693fb14607c305" memberName="noiseLevelR"
          virtualName="" explicitFocusOrder="0" pos="10% 50% 10% 20%" min="0.00010000000000000000479"
          max="1" int="0.00010000000000000000479" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="oscShape" id="b8e00a546e74d021" memberName="oscShape" virtualName=""
            explicitFocusOrder="0" pos="32% 10% 20% 5%" tooltip="Sin&#10;Saw&#10;Square"
            editable="0" layout="33" items="Sin&#10;Saw&#10;Square&#10;Triangle"
            textWhenNonSelected="Sin" textWhenNoItems="(no choices)"/>
  <TOGGLEBUTTON name="waveshapeBtn" id="c283a943a349164f" memberName="waveshapeBtn"
                virtualName="" explicitFocusOrder="0" pos="32% 15% 20% 5%" buttonText="Waveshape"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <COMBOBOX name="distortionType" id="21b389bce5927f5c" memberName="distortionType"
            virtualName="" explicitFocusOrder="0" pos="32% 4% 20% 5%" tooltip="Sin&#10;Saw&#10;Square"
            editable="0" layout="33" items="Hard Clipping&#10;Soft Clipping&#10;Soft Clipping EXP&#10;Full Wave Rect&#10;Half Wave Rect&#10;None"
            textWhenNonSelected="None" textWhenNoItems="(no choices)"/>
  <SLIDER name="noiseCutoff" id="78051a8350a460d5" memberName="noiseCutoff"
          virtualName="" explicitFocusOrder="0" pos="33.333% 50% 10% 20%"
          thumbcol="ffbbffbc" rotarysliderfill="7f00ff17" min="0.00010000000000000000479"
          max="1" int="0.00010000000000000000479" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="noiseLevelA" id="7190837eea8984e0" memberName="noiseResonance"
          virtualName="" explicitFocusOrder="0" pos="44% 50% 10% 20%" rotarysliderfill="7f008102"
          min="0" max="100" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
