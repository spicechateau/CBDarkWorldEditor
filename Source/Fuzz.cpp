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
    
    x = x * drive;
    
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
