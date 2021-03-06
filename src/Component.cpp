#include "Component.h"

Component::Component(){}

void Component::setup(glm::vec3 start){
	// set up gui
	params.setName("PARAMS");
	params.add(pos.set("POS", ofVec2f(0, 0), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
	gui.setup(params);

	// push a start point for lines (e.g. when splitting from another line)
	cps.push_back(start);
	regenCurve(false);
	color.set(ofRandom(128, 255), ofRandom(128, 255), ofRandom(128, 255));
}

void Component::draw(bool show_gui){
	float time = ofGetElapsedTimef();

	// make a new curve when current one is done drawing
	if(time >= ntime) regenCurve();

	// interpolate out points along the bezier curve
	// creates motion over time
	int step = timeToStep(time, ptime, ntime, points.size());
	pos = points[step];

	// colors shown in gui mode
	ofSetColor(show_gui ? color : ofColor::white);

	// "undraw" points from previous curve
	int i = 0;
	for(auto &p : ppoints){
		if(i++ >= step && i < ppoints.size()) ofDrawLine(p, ppoints[i]);
	}

	// draw points on current curve
	i = 0;
	for(auto &p : points){
		if(i++ >= step) break;
		ofDrawLine(p, points[i]);
	}

	// show gui if gui mode is on
	if(show_gui){
		gui.setPosition(pos->x, pos->y);
		gui.draw();
	}
}

void Component::regenCurve(bool end){
	// regenerate control points
	cps.erase(cps.begin(), cps.end() - 1);
	while(cps.size() < 4) cps.emplace_back(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0);
	// if(ret) cps.back() = glm::vec3(int(ofRandom(2)) * ofGetWidth(), int(ofRandom(2)) * ofGetHeight(), 0);
	if(ret) cps.back() = glm::vec3(ofGetWidth() / 2, ofGetHeight() / 2, 0);

	// reset curves + anim vars
	ppoints = points;
	points = evalBezier(cps, 1000);
	ptime = ofGetElapsedTimef();
	ntime = ptime + ofRandom(1, 3);
	ended = end;
	ret = ofRandom(0, 2) && !ret;
}

int Component::timeToStep(float t, float t_start, float t_end, int steps){
	return ofClamp((t - t_start) / (t_end - t_start) * steps, 0, steps - 1);
}
