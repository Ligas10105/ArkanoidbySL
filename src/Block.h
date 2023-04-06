//
// Created by ligas on 30.03.2023.
//
#include <SFML/Graphics.hpp>



class Block : public sf::Drawable{
public:
    Block(float t_X, float t_Y, float t_Width, float t_Height);
    Block() = delete;
    ~Block()  = default;

    void update();
    sf::Vector2f getPosition();


    float right();
    float left();
    float top();
    float bottom();

    bool isDestroyed();
    void destroy();
    sf::Vector2f getSize();
private:
    void draw(sf::RenderTarget& target,sf::RenderStates state) const override;
    sf::RectangleShape shape;
    bool destroyed{false};



};


