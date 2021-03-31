/*
  ==============================================================================

    Fuzz.h
    Created: 30 Mar 2021 11:30:01pm
    Author:  Tim Leete

  ==============================================================================
*/

#pragma once

class Fuzz {
    
public:
    
    float processSample (float x);
    
    void setDrive (float newDrive);
    
private:
    
    float drive = 1.f;
    
};
