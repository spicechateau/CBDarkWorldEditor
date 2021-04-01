/*
  ==============================================================================

    Distortin.cpp
    Created: 30 Mar 2021 11:11:40pm
    Author:  Tim Leete

  ==============================================================================
*/

#include "Distortion.h"
#include <JuceHeader.h>

float Distortion::processSample (float x)
{
    
    smoothDrive = alpha * smoothDrive + (1.f - alpha) * drive;

    float y = (2.f / M_PI) * atan(smoothDrive * x);
    
    return y;
}

void Distortion::setDrive (float newDrive)
{
    if (newDrive <= 10.f && newDrive >= 1.f){
        drive = newDrive;
    }
}

void Distortion::setFs (float newFs)
{
    Fs = newFs;
    alpha = exp(-log(9) / (Fs * smoothTime));
}
