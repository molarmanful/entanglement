#include "Component.h"

Component::Component(){}

void Component::setup(glm::vec3 start){
	params.setName("PARAMS");
	params.add(pos.set("POS", ofVec2f(0, 0), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
	gui.setup(params);

	cps.push_back(start);
	regenCurve(false);
}

void Component::draw(bool show_gui){
	float time = ofGetElapsedTimef();

	if(time >= ntime) regenCurve();

	int step = timeToStep(time, ptime, ntime, points.size());
	pos = points[step];

	int i = 0;
	for(auto &p : ppoints){
		if(i++ >= step && i < ppoints.size()) ofDrawLine(p, ppoints[i]);
	}

	i = 0;
	for(auto &p : points){
		if(i++ >= step) break;
		ofDrawLine(p, points[i]);
	}

	if(show_gui){
		gui.setPosition(pos->x, pos->y);
		gui.draw();
	}
}

void Component::regenCurve(bool end){
	cps.erase(cps.begin(), cps.end() - 1);
	while(cps.size() < 4) cps.emplace_back(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0);
	// if(ret) cps.back() = glm::vec3(int(ofRandom(2)) * ofGetWidth(), int(ofRandom(2)) * ofGetHeight(), 0);
	if(ret) cps.back() = glm::vec3(ofGetWidth() / 2, ofGetHeight() / 2, 0);

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
