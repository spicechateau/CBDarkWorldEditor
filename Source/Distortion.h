/*
  ==============================================================================

    Distortin.h
    Created: 30 Mar 2021 11:11:40pm
    Author:  Tim Leete

  ==============================================================================
*/

#pragma once

class Distortion {
    
public:
    
    float processSample (float x);
    
    void setDrive (float newDrive);
    
private:
    
    float drive = 1.f;
    
};
