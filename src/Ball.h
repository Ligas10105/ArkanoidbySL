//
// Created by ligas on 30.03.2023.
//

#include <SFML/Graphics.hpp>




class Ball : public sf::Drawable {
public:
    Ball(float t_X, float t_Y);
    Ball() = delete;
    ~Ball() = default;

    void update();

    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();

    sf::Vector2f getPosition();

    float left();
    float right();
    float top();
    float bottom();

private:
    sf::CircleShape shape;
    const float ballRadius{20.0f};
    const float ballVelocity{7.0f};
    sf::Vector2f velocity { ballVelocity, ballVelocity};
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};



