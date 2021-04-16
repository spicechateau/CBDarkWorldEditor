/*
  ==============================================================================

    MIDIParameters.cpp
    Created: 4 Apr 2021 1:04:17am
    Author:  Tim Leete

  ==============================================================================
*/

#include "MIDIParameters.h"
#include <JuceHeader.h>

void MIDIParameters::setBypass (bool darkOn, bool worldOn){
    if (darkOn && !worldOn)
        bypass = 100;
    else if (!darkOn && worldOn)
        bypass = 50;
    else if (darkOn && worldOn)
        bypass = 127;
    else
        bypass = 0;
}

void MIDIParameters::setDecay (int newDecay){
    decay = newDecay;
}

void MIDIParameters::setMix (int newMix){
    mix = newMix;
}

void MIDIParameters::setDwell (int newDwell){
    dwell = newDwell;
}

void MIDIParameters::setMod (int newMod){
    mod = newMod;
}

void MIDIParameters::setTone (int newTone){
    tone = newTone;
}

void MIDIParameters::setPreDelay (int newPreDelay){
    preDelay = newPreDelay;
}

void MIDIParameters::setDarkType (int newDarkType){
    darkType = newDarkType;
}

void MIDIParameters::setEffectOrder (int newEffectOrder){
    effectOrder = newEffectOrder;
}

void MIDIParameters::setWorldType (int newWorldType){
    worldType = newWorldType;
}
