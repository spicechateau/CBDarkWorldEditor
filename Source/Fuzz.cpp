/*
  ==============================================================================

    Fuzz.cpp
    Created: 30 Mar 2021 11:30:01pm
    Author:  Tim Leete

  ==============================================================================
*/

#include "Fuzz.h"
#include <JuceHeader.h>

float Fuzz::processSample (float x)
{
    float y;
    
    smoothDrive = alpha * smoothDrive + (1.f - alpha) * drive;
        
    x = x * smoothDrive;
    
    if (x > 0.5f){
        y = 0.5f;
    }
    else if (x < -0.5f){
        y = -0.5f;
    }
    else {
        y = x;
    }
    return y;
}

void Fuzz::setDrive (float newDrive)
{
    if (newDrive <= 10.f && newDrive > 0.01f){
        drive = newDrive;
    }
}

void Fuzz::setFs (float newFs)
{
    Fs = newFs;
    alpha = exp(-log(9) / (Fs * smoothTime));
}
