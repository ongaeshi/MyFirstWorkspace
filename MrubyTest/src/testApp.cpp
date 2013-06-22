#include "testApp.h"

#include <mruby.h>
#include <mruby/compile.h>
#include <stdio.h>

int myCircleX;
int myCircleY;
int myCircleRadius=100;

static mrb_value circle(mrb_state *mrb, mrb_value self)
{
    mrb_float x, y, radius;
    mrb_get_args(mrb, "fff", &x, &y, &radius);
    // printf("%f, %f, %f\n", x, y, radius);
    ofCircle(x, y, radius);
    return mrb_nil_value();
}

//--------------------------------------------------------------
void testApp::setup()
{
    mrb = mrb_open();

    // bind
    mrb_define_method(mrb, mrb->kernel_module, "circle", circle, MRB_ARGS_REQ(0));

    // load files
    FILE *fd = fopen("../src/sample.rb", "r");
    // printf("fd = %p", fd);
    mrb_load_file(mrb, fd);

    // call
    mrb_funcall(mrb, mrb_obj_value(mrb->kernel_module), "setup", 0);
    if (mrb->exc) {
        mrb_p(mrb, mrb_obj_value(mrb->exc));
    }

    // setup openFrameworks
    ofSetFrameRate(60);
    myCircleX = 300;
    myCircleY = 200;
}

//--------------------------------------------------------------
void testApp::update()
{
    mrb_funcall(mrb, mrb_obj_value(mrb->kernel_module), "update", 0);

    if (mrb->exc) {
        mrb_p(mrb, mrb_obj_value(mrb->exc));
    }
}

//--------------------------------------------------------------
void testApp::draw()
{
    // show fps
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);

    // draw circle from C++
    ofSetColor(255, 0, 255);
    ofCircle(myCircleX, myCircleY, myCircleRadius);

    // draw from mruby
    mrb_funcall(mrb, mrb_obj_value(mrb->kernel_module), "draw", 0);

    if (mrb->exc) {
        mrb_p(mrb, mrb_obj_value(mrb->exc));
    }
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
