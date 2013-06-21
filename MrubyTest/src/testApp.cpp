#include "testApp.h"

#include <mruby.h>
#include <mruby/proc.h>
#include <mruby/compile.h>

int myCircleX;
int myCircleY;
int myCircleRadius=100;
mrb_state* mrb;
struct mrb_parser_state* st;
mrbc_context* c;
int n;
struct RProc* proc;

static mrb_value circle(mrb_state *mrb, mrb_value self)
{
    ofCircle(200, 200, 30);
    // printf("call function\n");
    return mrb_nil_value();
}

//--------------------------------------------------------------
void testApp::setup()
{
    ofSetFrameRate(60);

    myCircleX = 300;
    myCircleY = 200;


    mrb = mrb_open();

    mrb_define_method(mrb, mrb->kernel_module, "circle", circle, MRB_ARGS_REQ(0));

    c =  mrbc_context_new(mrb);
    st = mrb_parse_string(mrb, "ciffrcle()", c);
    n = mrb_generate_code(mrb, st);
    mrb_pool_close(st->pool);
    proc = mrb_proc_new(mrb, mrb->irep[n]);
    // mrb_run(mrb, mrb_proc_new(mrb, mrb->irep[n]), mrb_nil_value());
    //mrb_run(mrb, mrb_proc_new(mrb, mrb->irep[n]), mrb_nil_value());

    mrb_run(mrb, proc, mrb_nil_value());

    if (mrb->exc) {
        mrb_p(mrb, mrb_obj_value(mrb->exc));
    }


    // mrb_close(mrb);
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

    mrb_run(mrb, proc, mrb_nil_value());
    // mrb_load_string(mrb, "circle()");

    // if (mrb->exc) {
    //     mrb_p(mrb, mrb_obj_value(mrb->exc));
    // }
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
