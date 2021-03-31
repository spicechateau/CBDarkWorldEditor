/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Distortion.h"
#include "Fuzz.h"

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

    float decay = 1.f; // Distortion drive
    float mix = 1.f; // Output gain
    float dwell = 1.f; // Fuzz drive
    int modify = 63;
    int tone = 63;
    int preDelay = 63;
    
    int darkType = 1;
    int effectOrder = 1;
    int worldType = 1;
    
    bool darkOn = false;
    bool worldOn = false;
    
private:
    
    Distortion myDistortion;
    Fuzz myFuzz;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CBDarkWorldEditorAudioProcessor)
};
