#include "testApp.hpp"

#include "BindApplication.hpp"
#include "BindGraphics.hpp"
#include "mruby.h"
#include "mruby/compile.h"
#include <stdio.h>
#include <unistd.h>

//--------------------------------------------------------------
testApp::testApp(const char* aFilename)
: mFilename(aFilename)
, mrb(NULL)
{
}

//--------------------------------------------------------------
void testApp::setup()
{
    // setup openFrameworks
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(255, 255, 255);

    mrb = mrb_open();

    // bind
    BindGraphics::Bind(mrb);
    BindApplication::Bind(mrb);

    // load files
    // FILE *fd = fopen("../src/sample.rb", "r");
    // FILE *fd = fopen("/Users/ongaeshi/Documents/of_v0.7.4_osx_release/apps/MyFirstWorkspace/MrubyTest/src/sample.rb", "r");
    FILE *fd = fopen(mFilename, "r");
    mrb_load_file(mrb, fd);

    // call
    mrb_funcall(mrb, mrb_obj_value(mrb->kernel_module), "setup", 0);
    if (mrb->exc) {
        mrb_p(mrb, mrb_obj_value(mrb->exc));
    }
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
    // ofSetColor(0, 0, 0);
    // ofDrawBitmapString("argc: " + ofToString(mArgc) + "\n" + "argv[0]: " + ofToString(mArgv[0]) + "\n" + "argv[1]: " + ofToString(mArgv[1]), 10, 200);

    // char dir[255];
    // getcwd(dir,255);
    // ofDrawBitmapString("cwd: " + ofToString(dir), 10, 300);

    // draw from mruby
    mrb_funcall(mrb, mrb_obj_value(mrb->kernel_module), "draw", 0);

    if (mrb->exc) {
        mrb_p(mrb, mrb_obj_value(mrb->exc));
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{
    // cout << "keyReleased " << key << endl;
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
    mrb_funcall(mrb, mrb_obj_value(mrb->kernel_module), "mouse_pressed", 3, mrb_fixnum_value(x), mrb_fixnum_value(y), mrb_fixnum_value(button));

    if (mrb->exc) {
        mrb_p(mrb, mrb_obj_value(mrb->exc));
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

//EOF
