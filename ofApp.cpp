#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	ofSetLineWidth(1.5);
	ofEnableDepthTest();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(270);

	for (int i = 0; i < 139; i++) {

		float radius = 100;
		float small_radius = 50;
		int start_deg = ofRandom(360) + ofGetFrameNum();
		int small_deg_param = ofRandom(4, 10);

		ofColor line_color;
		line_color.setHsb(ofRandom(255), 239, 239);

		float radius_span = 0.5;
		int deg_span = 2;
		for (int deg = start_deg; deg <= start_deg + 30; deg += 2) {

			ofSetColor(line_color, ofMap(deg, start_deg, start_deg + 30, 32, 255));

			ofPoint p1 = make_point(radius, small_radius, deg, deg * small_deg_param);
			ofPoint p2 = make_point(radius + radius_span, small_radius, deg + deg_span, (deg + deg_span) * small_deg_param);
			ofDrawLine(p1, p2);

			radius += radius_span;
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
ofPoint ofApp::make_point(float radius, float small_radius, float deg, float small_deg) {

	float x_1 = radius * cos(deg * DEG_TO_RAD);
	float y_1 = radius * sin(deg * DEG_TO_RAD);

	float x_2 = small_radius * cos(small_deg * DEG_TO_RAD) * cos(deg * DEG_TO_RAD);
	float y_2 = small_radius * cos(small_deg * DEG_TO_RAD) * sin(deg * DEG_TO_RAD);

	float x = x_1 + x_2;
	float y = y_1 + y_2;
	float z = small_radius * sin(small_deg * DEG_TO_RAD);

	return ofPoint(x, y, z);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(1280, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}