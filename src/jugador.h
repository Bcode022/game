#pragma once
#include "ofMain.h"

class jugador {
public:
	ofPoint pos;
	void setup(ofImage* _img, ofPoint _pos);
	void draw();
	void update();
	ofImage* img;
	bool izquierda, derecha, abajo, arriba;
	float width, height, vel;

};