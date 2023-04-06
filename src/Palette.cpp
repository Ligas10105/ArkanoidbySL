//
// Created by ligas on 30.03.2023.
//

#include "Palette.h"

Palette::Palette(float t_X, float t_Y) {

    shape.setPosition(t_X, t_Y);
    shape.setSize({paletteWidth, paletteHeight});
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(this->paletteWidth / 2, this->paletteHeight / 2);


}

void Palette::draw(sf::RenderTarget &target, sf::RenderStates state) const {
    target.draw(this->shape, state);
}

void Palette::update() {


    this->shape.move(velocity);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && this->left() > 0) {
        velocity.x = -paletteVelocity;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && this->right() < 800) {
        velocity.x = paletteVelocity;
    } else {
        velocity.x = 0;
    }
}


float Palette::left() {
    return this->shape.getPosition().x - shape.getSize().x / 2.f;
}

float Palette::right() {
    return this->shape.getPosition().x + shape.getSize().x / 2.f;
}

float Palette::top() {
    return this->shape.getPosition().y - shape.getSize().y / 2.f;
}

float Palette::bottom() {
    return this->shape.getPosition().y + shape.getSize().y / 2.f;
}

sf::Vector2f Palette ::getPosition() {
    return shape.getPosition();
}