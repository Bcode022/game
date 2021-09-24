#include "jugador.h"

void jugador::setup(ofImage * _img, ofPoint _pos) {
    img = _img;
    height = img->getHeight();
    width = img->getWidth();
    int getX();
    int getY();
    vel = 5;
    pos.set(_pos);
}


void jugador::draw() {
    img->draw(pos.x - width / 2, pos.y - height / 2);
}

void jugador::update() {
    if (arriba)
        pos.y -= vel;
    if (abajo)
        pos.y += vel;
    if (izquierda)
        pos.x -= vel;
    if (derecha)
        pos.x += vel;
}