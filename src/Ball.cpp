//
// Created by ligas on 30.03.2023.
//

#include "Ball.h"

Ball :: Ball(float t_X, float t_Y) {
    shape.setPosition(t_X, t_X);
    shape.setRadius( this -> ballRadius);
    shape.setFillColor(Color :: Red);
    shape.setOrigin(this -> ballRadius, this -> ballRadius);
}

void Ball::draw (RenderTarget& target, RenderStates state) const{
    target.draw(this -> shape, state);
}

void Ball :: update(){
    shape.move(this -> velocity);
    if (this -> left() < 0)
    {
        velocity.x = ballVelocity;
    }
    else if (this -> right() > 800){
        velocity.x = -ballVelocity;
    }
    else if (this -> top() < 0){
        velocity.y = ballVelocity;
    }
    else if (this -> bottom() > 600){
        velocity.y = -ballVelocity;
    }

}

float Ball :: left(){
    return this -> shape.getPosition().x - shape.getRadius();
}

float Ball :: right(){
    return this -> shape.getPosition().x + shape.getRadius();
}

float Ball :: top(){
    return this -> shape.getPosition().y - shape.getRadius();
}

float Ball :: bottom(){
    return this -> shape.getPosition().y + shape.getRadius();
}