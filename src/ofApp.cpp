//
//  ofApp.cpp
//  NoiseThresholdExample
//
//  Created by Andreasmuller on 15-4-29.
//
//

#include <ofApp.h>
//--------------------------------------------------------------
void ofApp::setup()
//At the begining of the program, to define the basic code condition.
{
    
    resolution.addListener(this, &ofApp::resolutionChanged );
    //to add the listener
    
    gui.setup( "Main", "Main.xml" );
    //set a gui
    
    gui.add( resolution.set( "Resolution", 512, 2, 1024 ) );
    //add a resolution for gui
    gui.add( noiseFrequency.set( "Noise Frequency", 80.0f, 0.00001f, 4096.0f ) );
    //add a noiseFrequency for gui
    gui.add( animate.set( "Animate", false ) );
    //add a animate for gui
    gui.add( doThreshold.set( "Threshold", false ) );
    //add a doThreshold for gui
    gui.add( thresholdLow.set( "Treshold Low", 0, 0, 255 ) );
    //add a thresholdLow for gui
    gui.add( thresholdHigh.set( "Treshold High", 127, 0, 255 ) );
    //add a thresholdHigh for gui
    gui.add( invert.set( "Invert Threshold", false ) );
    //add a invert for gui
    
    noiseStartX = 0;
    //noise start at 0
    noiseStartY = 0;
    //noise start at 0
    
    drawGui = true;
    
    noiseImage.allocate( resolution, resolution, OF_IMAGE_GRAYSCALE );
    //load the noise image
}

//--------------------------------------------------------------
void ofApp::update()
//set up a update class
{
    if( ofGetKeyPressed(OF_KEY_LEFT)  )  { noiseStartX += 5; }
    //keep press left
    if( ofGetKeyPressed(OF_KEY_RIGHT ) ) { noiseStartX -= 5; }
    //keep press right
    if( ofGetKeyPressed(OF_KEY_UP)  )    { noiseStartY += 5; }
    //keep press up
    if( ofGetKeyPressed(OF_KEY_DOWN ) )  { noiseStartY -= 5; }
    //keep press down
    
    float time = 0.0f;
    //hand out time
    if( animate ) time = ofGetElapsedTimef();
    
    ofPixelsRef pixels = noiseImage.getPixelsRef();
    //give the pixels
    
    int tmpIndex = 0;
    //to create the index
    for( int y = 0; y < noiseImage.getHeight(); y++ )
        //hight of y
    {
        for( int x = 0; x < noiseImage.getWidth(); x++ )
            //width of x
        {
            // We're grabbing a single reading from the noise function here, but we can also add together more
            // readings at different frequencies to make more complex patterns
            
            float tmpNoise = ofNoise( (noiseStartX + x) / noiseFrequency, (noiseStartY + y) / noiseFrequency, time );
            //give a new vector
            
            pixels[tmpIndex] = tmpNoise * 255.0f;
            tmpIndex++;
            //i am not sure
        }
    }
    
    if( doThreshold)
        //if .. else
    {
        threshold( false );
        //to close it
    }
    
    noiseImage.update();
    // uploads the new pixels to the gfx card
}

//--------------------------------------------------------------
void ofApp::threshold( bool _upload )
//upload bool
{
    ofPixelsRef pixels = noiseImage.getPixelsRef();
    //i am not sure
    
    int tmpIndex = 0;
    //index is 0
    for( int y = 0; y < noiseImage.getHeight(); y++ )
        //the max and min of y
    {
        for( int x = 0; x < noiseImage.getWidth(); x++ )
            //the max and min of x
        {
            if( pixels[tmpIndex] >= thresholdLow && pixels[tmpIndex] <= thresholdHigh )
                
                
            {
                pixels[tmpIndex] = 255;
                
            }
            else
                //if ... else
            {
                pixels[tmpIndex] = 0;
                
            }
            
            if( invert )
                
            {
                pixels[tmpIndex] = 255 - pixels[tmpIndex];
                
            }
            
            tmpIndex++;
            // I am not sure pixels and tmpIndex.
        }
    }
    
    
    if( _upload )
        //if upload
    {
        noiseImage.update();
        //update image
    }
}


//--------------------------------------------------------------
void ofApp::draw()

{
    ofBackgroundGradient( ofColor(0), ofColor(40), OF_GRADIENT_CIRCULAR );
    //set the background color
    
    ofRectangle imageRect(0,0,noiseImage.getWidth(), noiseImage.getHeight() );
    //the size of rect
    imageRect.scaleTo( ofRectangle(0,0,ofGetWidth(),ofGetHeight()) );
    //the size of image rect
    noiseImage.draw( imageRect );
    //draw the imge rect
    
    if( drawGui )
        //if ... else
    {
        gui.draw();
        //draw the gui
    }
    
}

//--------------------------------------------------------------
void ofApp::resolutionChanged( int& _res )
//hand out the resolution change
{
    noiseImage.allocate( _res, _res, OF_IMAGE_GRAYSCALE );
    //the function of noise image
}


//--------------------------------------------------------------
void ofApp::keyPressed( int _key )
//Keyboard control setup.
{
    if( _key == 'f' )
        //key button f
    {
        ofToggleFullscreen();
        //full screen setup
    }
}