#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
}

//--------------------------------------------------------------
void testApp::update()
{
}

//--------------------------------------------------------------
void testApp::draw()
{
    ofSetColor(255, 255, 255);
    ofCircle(200, 300, 60);

    ofSetColor(255, 0, 255);
    ofCircle(300, 300, 60);

    ofSetColor(0, 255, 255);
    ofCircle(500, 500, 100);

    ofSetColor(0, 255, 128);
    ofRect(300, 300, 200, 200);

    ofSetColor(0, 128, 128);
    ofTriangle(400, 100, 500, 200, 300, 200);

    ofSetColor(255, 128, 128);
    ofCurve(500, 100, 600, 100, 700, 400, 700, 300);

    ofSetColor(255, 255, 128);
    ofLine(0, 0, 400, 400);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{
}
