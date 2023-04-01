//
// Created by ligas on 30.03.2023.
//

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;



class Palette : public :: Drawable {
public:
    Palette(float t_X, float t_Y);
    Palette() = delete;
    ~Palette() = default;

    void update();
    float right();
    float left();
    float top();
    float bottom();

    Vector2f getPosition();

private:
    void draw(RenderTarget& target, RenderStates state) const override;
    RectangleShape shape;
    const float paletteWidth {100.0f};
    const float paletteHeight {30.0f};
    const float paletteVelocity {5.0f};
    Vector2f velocity {paletteVelocity, 0.f};






};





