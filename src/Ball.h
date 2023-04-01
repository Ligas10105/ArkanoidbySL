//
// Created by ligas on 30.03.2023.
//

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;


class Ball : public Drawable {
public:
    Ball(float t_X, float t_Y);
    Ball() = delete;
    ~Ball() = default;

    void update();

    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();

    Vector2f getPosition();

    float left();
    float right();
    float top();
    float bottom();

private:
    CircleShape shape;
    const float ballRadius{20.0f};
    const float ballVelocity{7.0f};
    Vector2f velocity { ballVelocity, ballVelocity};
    void draw(RenderTarget& target, RenderStates state) const override;
};



