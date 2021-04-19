#ifndef COMPONENT_H
#define COMPONENT_H

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxCurve.h"

class Component {
	public:
		Component();

		void setup(glm::vec3 start = glm::vec3(0, 0, 0));
		void draw(bool show_gui = false);
		void regenCurve(bool end = true);
		int timeToStep(float t, float t_start, float t_end, int steps);

		ofxPanel gui;

		ofParameterGroup params;
		ofParameter<ofVec2f> pos;

		vector<glm::vec3> cps;
		vector<glm::vec3> ppoints;
		vector<glm::vec3> points;

		float ptime;
		float ntime;

		bool ended;
		bool ret;

		ofColor color;
};

#endif
