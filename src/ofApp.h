#pragma once

#include "ofMain.h"
#include "Component.h"

class ofApp : public ofBaseApp{

	public:
		void addComponent(glm::vec3 p = glm::vec3(0, 0, 0));
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		vector<shared_ptr<Component>> components;
		vector<glm::vec3> qcomp;

		bool show_gui;
};
