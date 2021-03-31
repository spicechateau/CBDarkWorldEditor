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
    float y = (2.f / M_PI) * atan(drive * x);
    
    return y;
}

void Distortion::setDrive (float newDrive)
{
    if (newDrive <= 10.f && newDrive >= 1.f){
        drive = newDrive;
    }
}
