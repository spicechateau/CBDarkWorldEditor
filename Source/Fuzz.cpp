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
    if (x > 0.35f){
        y = 0.35f;
    }
    else if (x < -0.35f){
        y = -0.35f;
    }
    else {
        y = x;
    }
    return y;
}

void Fuzz::setDrive (float newDrive)
{
    if (newDrive <= 10.f && newDrive >= 1.f){
        drive = newDrive;
    }
}
