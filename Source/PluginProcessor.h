/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "MIDIChange.h"
#include "MIDIParameters.h"

//==============================================================================
/**
*/
class CBDarkWorldEditorAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    CBDarkWorldEditorAudioProcessor();
    ~CBDarkWorldEditorAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    juce::AudioParameterBool * darkOn;
    juce::AudioParameterBool * worldOn;
    
    juce::AudioParameterInt * decay;
    juce::AudioParameterInt * mix;
    juce::AudioParameterInt * dwell;
    juce::AudioParameterInt * modify;
    juce::AudioParameterInt * tone;
    juce::AudioParameterInt * preDelay;
    
    juce::AudioParameterInt * darkType;
    juce::AudioParameterInt * effectOrder;
    juce::AudioParameterInt * worldType;
    
    double startTime;
    
private:
    MIDIChange midiChange;
    MIDIParameters midiParams;
    
    int midiChannel = 1;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CBDarkWorldEditorAudioProcessor)
};
