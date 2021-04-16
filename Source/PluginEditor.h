/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class CBDarkWorldEditorAudioProcessorEditor  : public               juce::AudioProcessorEditor,
                                                public juce::Slider::Listener,
                                                public juce::ComboBox::Listener,
                                                public juce::Button::Listener,
                                                public juce::Timer
{
public:
    CBDarkWorldEditorAudioProcessorEditor (CBDarkWorldEditorAudioProcessor&);
    ~CBDarkWorldEditorAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged (juce::Slider * slider) override;
    void comboBoxChanged (juce::ComboBox * comboBox) override;
    void buttonClicked (juce::Button * button) override;
    void timerCallback () override;

private:
    CBDarkWorldEditorAudioProcessor& audioProcessor;
    
    juce::Slider decaySlider;
    juce::Slider mixSlider;
    juce::Slider dwellSlider;
    juce::Slider modifySlider;
    juce::Slider toneSlider;
    juce::Slider preDelaySlider;
    
    juce::ComboBox darkTypeBox;
    juce::ComboBox effectOrderBox;
    juce::ComboBox worldTypeBox;
    
    juce::Label decayLabel;
    juce::Label mixLabel;
    juce::Label dwellLabel;
    juce::Label modifyLabel;
    juce::Label toneLabel;
    juce::Label preDelayLabel;
    juce::Label darkTypeLabel;
    juce::Label effectOrderLabel;
    juce::Label worldTypeLabel;
    juce::Label darkWorldOnLabel;
    
    juce::ToggleButton darkOnButton;
    juce::ToggleButton worldOnButton;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CBDarkWorldEditorAudioProcessorEditor)
};
