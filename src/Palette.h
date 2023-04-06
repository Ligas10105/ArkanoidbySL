//
// Created by ligas on 30.03.2023.
//

#include <SFML/Graphics.hpp>




class Palette : public sf::Drawable {
public:
    Palette(float t_X, float t_Y);
    Palette() = delete;
    ~Palette() = default;

    void update();
    float right();
    float left();
    float top();
    float bottom();

    sf::Vector2f getPosition();

private:
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
    sf::RectangleShape shape;
    const float paletteWidth {100.0f};
    const float paletteHeight {30.0f};
    const float paletteVelocity {5.0f};
    sf::Vector2f velocity {paletteVelocity, 0.f};






};





