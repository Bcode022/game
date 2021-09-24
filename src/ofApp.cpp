#include "ofApp.h"

long seg;

const int numParticles = 1;
particle myParticle[numParticles];
jugador myPlayer;

int particle::getX() {
    return (pos_p.x);
}
int particle::getY() {
    return (pos_p.y);
}

particle::particle() {

}

void particle::update() {
    if (!alive)
        return;

    time = ofGetFrameNum() / 60;
    lifetime = time % 10;

    if (pos_p.x < myPlayer.width && pos_p.x > myPlayer.width && pos_p.y < myPlayer.height && pos_p.y > myPlayer.height) {
        alive = false; //kill self if moused over
    }

}

void particle::draw() {
    if (alive) {
        ofSetLineWidth(3);
        ofPushMatrix();
        ofTranslate(pos_p.x, pos_p.y);
        ofDrawTriangle(20, 20, 30, 40, 10, 40);
        ofPopMatrix();
    }

}

//--------------------------------------------------------------
void ofApp::setup(){
    fuente.load("arial.ttf", 32);
	video.load("imagenes/agua.mp4");
    imagen_jugador.load("imagenes/player1.png");
    inicio_jugador.set(256, 450);
    jugador_1.setup(&imagen_jugador, inicio_jugador);
}

//--------------------------------------------------------------
void ofApp::update() {
    seg = ofGetFrameNum() / 60;
    video.update();
    jugador_1.update();

    for (int i = 0; i < numParticles; i++) {
        if (myParticle[i].alive == false) {
            myParticle[i].alive = true;
            myParticle[i].pos_p = ofPoint(ofRandom(50, ofGetWidth() - 50), ofRandom(100, ofGetHeight() - 100));
            return;
        }
    }

    for (int i = 0; i < numParticles; i++) {
        myParticle[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    string tiempo = ofToString(0 + seg);
	video.draw(0, 0, 800, 600);
	video.play();
	jugador_1.draw();
    fuente.drawString("tiempo:" + tiempo, 10, 50);

    for (int i = 0; i < numParticles; i++) {
        myParticle[i].draw();
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_LEFT)
        jugador_1.izquierda = true;
    if (key == OF_KEY_RIGHT)
        jugador_1.derecha = true;
    if (key == OF_KEY_UP)
        jugador_1.arriba = true;
    if (key == OF_KEY_DOWN)
        jugador_1.abajo = true;
    if (key == ' ') {
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == OF_KEY_LEFT)
        jugador_1.izquierda = false;
    if (key == OF_KEY_RIGHT)
        jugador_1.derecha = false;
    if (key == OF_KEY_UP)
        jugador_1.arriba = false;
    if (key == OF_KEY_DOWN)
        jugador_1.abajo = false;
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
