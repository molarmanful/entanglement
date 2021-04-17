#include "ofApp.h"

void ofApp::addComponent(glm::vec3 p){
	auto c = make_shared<Component>();
	components.push_back(c);
	components.back()->setup(p);
}

//--------------------------------------------------------------
void ofApp::setup(){
	addComponent();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(0);

	for(auto &c : components){
		if(components.size() < 10 && c->ended){
			qcomp.push_back(c->cps.front());
			c->ended = false;
		}

		c->draw(show_gui);

		// for(auto &d : components){
		// 	ofDrawLine(ofVec2f(c->pos), ofVec2f(d->pos));
		// }
	}

	for(auto q : qcomp) addComponent(q);
	qcomp.clear();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == ' ') show_gui = !show_gui;
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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
