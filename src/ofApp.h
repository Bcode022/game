#pragma once

#include "ofMain.h"
#include "jugador.h"

class particle {
private:
	ofVec2f vel;
	//    int rad = 10;

public:
	particle();
	ofPoint pos_p;
	bool alive = false;
	void update();
	void draw();
	int getX();
	int getY();
	int lifetime;
	int time;
};

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	jugador jugador_1;
	ofImage imagen_jugador;
	ofVideoPlayer video;
	ofPoint inicio_jugador;
	ofTrueTypeFont fuente;

};
