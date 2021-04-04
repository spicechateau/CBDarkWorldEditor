/*
  ==============================================================================

    MIDIChange.cpp
    Created: 3 Apr 2021 5:33:23pm
    Author:  Tim Leete

  ==============================================================================
*/

#include "MIDIChange.h"
#include <JuceHeader.h>

void MIDIChange::processMIDI (juce::MidiBuffer& MidiMessages)
{
    processedBuffer.clear();
    processMIDIInput (MidiMessages);
    MidiMessages.swapWith (processedBuffer);
}

void MIDIChange::processMIDIInput (const juce::MidiBuffer& MidiMessages)
{
    juce::MidiBuffer::Iterator it (MidiMessages);
    juce::MidiMessage currentMessage;
    int samplePos;
    
    while (it.getNextEvent(currentMessage, samplePos))
    {
        currentMessage = juce::MidiMessage::controllerEvent (midiChannel, 103, midiParams.bypass);
        
        processedBuffer.addEvent (currentMessage, samplePos);
    }
}
