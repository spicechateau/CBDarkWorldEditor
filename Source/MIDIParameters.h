/*
  ==============================================================================

    MIDIParameters.h
    Created: 4 Apr 2021 1:04:17am
    Author:  Tim Leete

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class MIDIParameters
{
    
public:
    void setBypass (bool darkOn, bool worldOn);
    
    void setDecay (int decay);
    void setMix (int mix);
    void setDwell (int dwell);
    void setMod (int mod);
    void setTone (int tone);
    void setPreDelay (int predelay);
    
    void setDarkType (int darkType);
    void setEffectOrder (int effectOrder);
    void setWorldType (int worldType);
    
    int bypass;
    int decay;
    int mix;
    int dwell;
    int mod;
    int tone;
    int preDelay;
    int darkType;
    int effectOrder;
    int worldType;
    
private:
};
