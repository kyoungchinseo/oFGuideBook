#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(255,0,130);

    buttonState= 0;
    potValue= 0;
    PWMValue = 0;

    font.load("verdana.ttf", 48);
    //ard.connect("/dev/tty.usbmodemfd121", 57600);
    arduino.connect("/dev/cu.usbmodem1421", 57600);

    ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
    bSetupArduino= false;
}

//--------------------------------------------------------------
void ofApp::update(){
    updateArduino();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0, 127);
    ofDrawRectangle(15, 15, 770, 65);
    ofSetColor(0, 0, 0, 127);
    ofDrawRectangle(15, 95, 770, 270);

    float value = ofMap(potValue, 0, 1023, 0, 255);
    ofSetColor(value, value, value);
    ofDrawRectangle(15, 380, 770, 205);

    ofSetColor(255, 255, 255);
    if(!bSetupArduino){
        font.drawString("arduino not ready...\n", 20, 70);
    } else{
        font.drawString("arduino FIRMATA\n", 20, 70);
        font.drawString("analog input: " + ofToString(potValue), 20, 165);
        font.drawString("button state: " + ofToString(buttonState), 20, 240);
        font.drawString("PWM: " + ofToString(PWMValue), 20,315);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    arduino.sendDigital(13, ARD_HIGH);
    digitalPinChanged(13);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    arduino.sendDigital(13, ARD_LOW);
    digitalPinChanged(13);
}

void ofApp::setupArduino(const int& version) {
    // remove listener because we don't need it anymore
    ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);
    // it is now safe to send commands to the Arduino
    bSetupArduino= true;
    // set pin A0 to analog input
    arduino.sendAnalogPinReporting(0, ARD_ANALOG);
    // set pin D13 as digital output
    arduino.sendDigitalPinMode(13, ARD_OUTPUT);
    // set pin D9 as PWM (analog output)
    arduino.sendDigitalPinMode(9, ARD_PWM);
    // Listen for changes on the digital and analog pins
    ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

void ofApp::updateArduino(){
    arduino.update();
    if(bSetupArduino) {
        PWMValue = (int)(128 + 128 * sin(ofGetElapsedTimef()));
        arduino.sendPwm(9, PWMValue);
    }
}

void ofApp::digitalPinChanged(const int& pinNum) {
    buttonState = arduino.getDigital(pinNum);
}
void ofApp::analogPinChanged(const int& pinNum) {
    potValue= arduino.getAnalog(pinNum);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
