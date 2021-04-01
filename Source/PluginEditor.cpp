/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
CBDarkWorldEditorAudioProcessorEditor::CBDarkWorldEditorAudioProcessorEditor (CBDarkWorldEditorAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (300, 420);
    
    decaySlider.addListener(this);
    decaySlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    decaySlider.setBounds (1, 60, 100, 100);
    decaySlider.setRange (1, 10, .01);
    decaySlider.setColour(1, juce::Colours::white);
    decaySlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 30, 20);
    decaySlider.setValue (audioProcessor.decay);
    addAndMakeVisible (decaySlider);
    
    addAndMakeVisible (decayLabel);
    decayLabel.setText ("Decay", juce::dontSendNotification);
    decayLabel.setBounds (1, 45, 100, 20);
    decayLabel.setJustificationType (juce::Justification::centred);
    
    mixSlider.addListener(this);
    mixSlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    mixSlider.setBounds (decaySlider.getRight(), 60, 100, 100);
    mixSlider.setRange (0, 4, .01);
    mixSlider.setSkewFactorFromMidPoint (1);
    mixSlider.setColour(1, juce::Colours::white);
    mixSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 30, 20);
    mixSlider.setValue (audioProcessor.mix);
    addAndMakeVisible(mixSlider);
    
    addAndMakeVisible (mixLabel);
    mixLabel.setText ("Mix", juce::dontSendNotification);
    mixLabel.setBounds (decayLabel.getRight(), 45, 100, 20);
    mixLabel.setJustificationType (juce::Justification::centred);
    
    dwellSlider.addListener(this);
    dwellSlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    dwellSlider.setBounds (mixSlider.getRight(), 60, 100, 100);
    dwellSlider.setRange (.01, 10, .01);
    dwellSlider.setSkewFactorFromMidPoint (1);
    dwellSlider.setColour(1, juce::Colours::white);
    dwellSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 30, 20);
    dwellSlider.setValue (audioProcessor.dwell);
    addAndMakeVisible(dwellSlider);
    
    addAndMakeVisible (dwellLabel);
    dwellLabel.setText ("Dwell", juce::dontSendNotification);
    dwellLabel.setBounds (mixLabel.getRight(), 45, 100, 20);
    dwellLabel.setJustificationType (juce::Justification::centred);
    
    modifySlider.addListener(this);
    modifySlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    modifySlider.setBounds (1, 185, 100, 100);
    modifySlider.setRange (1, 127, 1);
    modifySlider.setColour(1, juce::Colours::white);
    modifySlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 30, 20);
    modifySlider.setValue (audioProcessor.modify);
    addAndMakeVisible(modifySlider);
    
    addAndMakeVisible (modifyLabel);
    modifyLabel.setText ("Modify", juce::dontSendNotification);
    modifyLabel.setBounds (1, 170, 100, 20);
    modifyLabel.setJustificationType (juce::Justification::centred);
    
    toneSlider.addListener(this);
    toneSlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    toneSlider.setBounds (modifySlider.getRight(), 185, 100, 100);
    toneSlider.setRange (1, 127, 1);
    toneSlider.setColour(1, juce::Colours::white);
    toneSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 30, 20);
    toneSlider.setValue (audioProcessor.tone);
    addAndMakeVisible(toneSlider);
    
    addAndMakeVisible (toneLabel);
    toneLabel.setText ("Tone", juce::dontSendNotification);
    toneLabel.setBounds (modifyLabel.getRight(), 170, 100, 20);
    toneLabel.setJustificationType (juce::Justification::centred);
    
    preDelaySlider.addListener(this);
    preDelaySlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    preDelaySlider.setBounds (toneSlider.getRight(), 185, 100, 100);
    preDelaySlider.setRange (1, 127, 1);
    preDelaySlider.setColour(1, juce::Colours::white);
    preDelaySlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 30, 20);
    preDelaySlider.setValue (audioProcessor.preDelay);
    addAndMakeVisible(preDelaySlider);
    
    addAndMakeVisible (preDelayLabel);
    preDelayLabel.setText ("Pre Delay", juce::dontSendNotification);
    preDelayLabel.setBounds (toneLabel.getRight(), 170, 100, 20);
    preDelayLabel.setJustificationType (juce::Justification::centred);
    
    addAndMakeVisible (darkTypeBox);
    darkTypeBox.setBounds (10, 330, 80, 20);
    darkTypeBox.addItem ("Mod", 1);
    darkTypeBox.addItem ("Shimmer", 2);
    darkTypeBox.addItem ("Black", 3);
    darkTypeBox.addListener (this);
    
    addAndMakeVisible (darkTypeLabel);
    darkTypeLabel.setText ("Dark Type", juce::dontSendNotification);
    darkTypeLabel.setBounds (1, 305, 100, 20);
    darkTypeLabel.setJustificationType (juce::Justification::centred);
    
    addAndMakeVisible (effectOrderBox);
    effectOrderBox.setBounds (darkTypeBox.getRight() + 20, 330, 80, 20);
    effectOrderBox.addItem ("Parallel", 1);
    effectOrderBox.addItem ("D > W", 2);
    effectOrderBox.addItem ("W > D", 3);
    effectOrderBox.addListener (this);
    
    addAndMakeVisible (effectOrderLabel);
    effectOrderLabel.setText ("Effect Order", juce::dontSendNotification);
    effectOrderLabel.setBounds (darkTypeLabel.getRight(), 305, 100, 20);
    effectOrderLabel.setJustificationType (juce::Justification::centred);
    
    addAndMakeVisible (worldTypeBox);
    worldTypeBox.setBounds (effectOrderBox.getRight() + 20, 330, 80, 20);
    worldTypeBox.addItem ("Hall", 1);
    worldTypeBox.addItem ("Plate", 2);
    worldTypeBox.addItem ("Spring", 3);
    worldTypeBox.addListener (this);
    
    addAndMakeVisible (worldTypeLabel);
    worldTypeLabel.setText ("World Type", juce::dontSendNotification);
    worldTypeLabel.setBounds (effectOrderLabel.getRight(), 305, 100, 20);
    worldTypeLabel.setJustificationType (juce::Justification::centred);
    
    addAndMakeVisible (darkOnButton);
    darkOnButton.setToggleState (audioProcessor.darkOn, juce::dontSendNotification);
    darkOnButton.setBounds (40, 370, 30, 30);
    
    addAndMakeVisible (worldOnButton);
    worldOnButton.setToggleState (audioProcessor.worldOn, juce::dontSendNotification);
    worldOnButton.setBounds (240, 370, 30, 30);
    
    addAndMakeVisible (darkWorldOnLabel);
    darkWorldOnLabel.setText ("Dark ON / World ON", juce::dontSendNotification);
    darkWorldOnLabel.setBounds (50, 365, 200, 40);
    darkWorldOnLabel.setFont (16.f);
    darkWorldOnLabel.setJustificationType (juce::Justification::centred);
}

CBDarkWorldEditorAudioProcessorEditor::~CBDarkWorldEditorAudioProcessorEditor()
{
}

//==============================================================================
void CBDarkWorldEditorAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::transparentWhite);
    g.setFont (30.0f);
    g.drawFittedText ("Dark World Editor", 50, 10, 200, 25, juce::Justification::centred, 1);
}

void CBDarkWorldEditorAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void CBDarkWorldEditorAudioProcessorEditor::sliderValueChanged(juce::Slider * slider)
{
    if (slider == &decaySlider)
    {
        audioProcessor.decay = decaySlider.getValue();
    }
    
    if (slider == &mixSlider)
    {
        audioProcessor.mix = mixSlider.getValue();
    }
    
    if (slider == &dwellSlider)
    {
        audioProcessor.dwell = dwellSlider.getValue();
    }
    
    if (slider == &modifySlider)
    {
        audioProcessor.modify = modifySlider.getValue();
    }
    
    if (slider == &toneSlider)
    {
        audioProcessor.tone = toneSlider.getValue();
    }
    
    if (slider == &preDelaySlider)
    {
        audioProcessor.preDelay = preDelaySlider.getValue();
    }
}

void CBDarkWorldEditorAudioProcessorEditor::comboBoxChanged(juce::ComboBox * comboBox)
{
    
}

void CBDarkWorldEditorAudioProcessorEditor::buttonClicked (juce::Button * button)
{
    if (button == &darkOnButton){
        audioProcessor.darkOn = !audioProcessor.darkOn;
    }
    
    if (button == &worldOnButton)
    {
        audioProcessor.worldOn = !audioProcessor.worldOn;
    }
}
