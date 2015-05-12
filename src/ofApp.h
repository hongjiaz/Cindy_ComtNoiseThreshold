//  Created by Andreasmuller in 2015.

#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp
//public class
{
public:
    //public
    
    //--------------------------------------------------------------
    void setup();
    void update();
    
    void threshold( bool _upload );
    
    void draw();
    
    //--------------------------------------------------------------
    void resolutionChanged( int& _res );
    //--------------------------------------------------------------
    void keyPressed( int _key );
    ofParameter<int> resolution;
    //to hand out resolution
    ofParameter<float> noiseFrequency;
    //to hand out noiseFrequency
    ofParameter<bool> animate;
    //to hand out animate
    
    ofParameter<bool> doThreshold;
    //to hand out doThreshold
    ofParameter<int> thresholdLow;
    //to hand out thresholdLow
    ofParameter<int> thresholdHigh;
    //to hand out thresholdHigh
    ofParameter<bool> invert;
    //to hand out invert
    
    int noiseStartX;
    // to hand out noise Start X
    int noiseStartY;
    //to hand out noise Start Y
    
    ofImage noiseImage;
    //load the image
    
    ofxPanel gui;
    //gui function
    bool drawGui;
    //draw the gui
};
