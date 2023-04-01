//
// Created by ligas on 30.03.2023.
//
#include <SFML/Graphics.hpp>

using namespace sf;

class Block : public sf :: Drawable{
public:
    Block(float t_X, float t_Y, float t_Width, float t_Height);
    Block() = delete;
    ~Block()  = default;

    void update();
    Vector2f getPosition();


    float right();
    float left();
    float top();
    float bottom();

    bool isDestroyed();
    void destroy();
    Vector2f getSize();
private:
    void draw(RenderTarget& target, RenderStates state) const override;
    RectangleShape shape;
    bool destroyed{false};



};


