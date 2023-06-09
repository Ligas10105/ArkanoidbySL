//
// Created by ligas on 30.03.2023.
//

#include "Ball.h"


Ball :: Ball(float t_X, float t_Y) {
    shape.setPosition(t_X, t_X);
    shape.setRadius( this -> ballRadius);
    shape.setFillColor(sf::Color :: Red);
    shape.setOrigin(this -> ballRadius, this -> ballRadius);
}

void Ball::draw (sf::RenderTarget& target, sf::RenderStates state) const{
    target.draw(this -> shape, state);
}

void Ball :: update(){
    shape.move(velocity);
    if (left() < 0)
    {
        velocity.x = ballVelocity;
    }
    else if (right() > 800){
        velocity.x = -ballVelocity;
    }
    else if (top() < 0){
        velocity.y = ballVelocity;
    }
    else if (bottom() > 600){
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

void Ball :: moveDown(){
    this -> velocity.y = -ballVelocity;
}

void Ball :: moveUp() {
    this -> velocity.y = ballVelocity;
}

void Ball ::moveRight() {
    this -> velocity.x = ballVelocity;
}

void Ball ::moveLeft() {
    this -> velocity.x = -ballVelocity;
}

sf::Vector2f Ball ::getPosition() {
    return shape.getPosition();
}