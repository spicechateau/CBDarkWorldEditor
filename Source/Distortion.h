/*
  ==============================================================================

    Distortin.h
    Created: 30 Mar 2021 11:11:40pm
    Author:  Tim Leete

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class Distortion {
    
public:
    
    float processSample (float x);
    
    void setDrive (float newDrive);
    
    void setFs (float newFs);
    
private:
    
    float drive = 1.f;
    
    float smoothDrive = 1.f;
    float Fs = 48000.f;
    
    float smoothTime = 0.01;
    float alpha = exp(-log(9)/(Fs * smoothTime));
    
};
