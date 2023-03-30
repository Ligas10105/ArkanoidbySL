//
// Created by ligas on 30.03.2023.
//

#include "Palette.h"

Palette :: Palette (float t_X, float t_Y) {

    shape.setPosition(t_X, t_Y);
    shape.setSize({paletteWidth, paletteHeight });
    shape.setFillColor(Color :: Red);
    shape.setOrigin(this -> paletteWidth/2, this -> paletteHeight/2);



}

void Palette :: draw (RenderTarget& target, RenderStates state) const{
    target.draw(this -> shape, state);
}

void Palette :: update(){
    this -> shape.move(velocity);
    if (this -> left() < 0)
    {
        velocity.x = paletteVelocity;
    }
    else if (this -> right() > 800){
        velocity.x = -paletteVelocity;

    }


}

float Palette :: left(){
    return this -> shape.getPosition().x - shape.getSize().x / 2.f;
}

float Palette :: right(){
    return this -> shape.getPosition().x + shape.getSize().x / 2.f;
}

float Palette :: top(){
    return this -> shape.getPosition().y - shape.getSize().y / 2.f;
}

float Palette :: bottom(){
    return this -> shape.getPosition().y + shape.getSize().y / 2.f;
}
