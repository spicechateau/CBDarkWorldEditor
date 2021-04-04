/*
  ==============================================================================

    MIDIChange.h
    Created: 3 Apr 2021 5:33:23pm
    Author:  Tim Leete

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "MIDIParameters.h"

class MIDIChange
{
    
public:
    void processMIDI (juce::MidiBuffer& MidiMessages);
    
    void processMIDIInput (const juce::MidiBuffer& MidiMessages);

    juce::MidiBuffer processedBuffer;
    
private:
    int midiChannel = 16;
    
    MIDIParameters midiParams;
};
