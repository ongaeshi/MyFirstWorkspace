#include "testApp.h"

#include <mruby.h>
#include <mruby/compile.h>

int myCircleX;
int myCircleY;
int myCircleRadius=100;

//--------------------------------------------------------------
void testApp::setup()
{
    ofSetFrameRate(60);

    myCircleX = 300;
    myCircleY = 200;


    mrb_state* mrb = mrb_open();
    mrb_load_string(mrb, "puts 'hello world'");
    mrb_close(mrb);
}

//--------------------------------------------------------------
void testApp::update()
{
}

//--------------------------------------------------------------
void testApp::draw()
{
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);

    ofSetColor(255, 0, 255);
    ofCircle(myCircleX, myCircleY, myCircleRadius);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    int speed = 8;

    if (key == 356) {
        myCircleX -= speed;
    } else if (key == 358) {
        myCircleX += speed;
    }

    if (key == 357) {
        myCircleY -= speed;
    } else if (key == 359) {
        myCircleY += speed;
    }
    // cout << "keyPressed " << key << endl;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{
    cout << "keyReleased " << key << endl;
    // printf("keyReleased %d\n", key);
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{
    // cout << "mouseMoved: " << x << ", " << y << endl;
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{
    // cout << "mouseDragged: " << x << ", " << y << " button: " << button << endl;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{
    float distance = ofDist(myCircleX, myCircleY, x, y);

    if (distance < myCircleRadius) {
        myCircleRadius++;
    }
    // cout << "mousePressed: " << x << ", " << y << " button: " << button << endl;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{
     // cout << "mouseReleased: " << x << ", " << y << " button: " << button << endl;
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
