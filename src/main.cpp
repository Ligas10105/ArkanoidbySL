#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "Palette.h"


using namespace std;
using namespace sf;

int main() {
    Ball ball(400, 300);
    Palette palette(400, 550);
    RenderWindow window{VideoMode(800, 600), "ArkanoidbySL"};
    window.setFramerateLimit(60);
    Event event;
    while (true) {
        window.clear(Color::Black);
        window.pollEvent(event);

        if (event.type == Event::Closed) {
            window.close();
            break;
        }
        ball.update();
        palette.update();
        window.draw(ball);
        window.draw(palette);
        window.display();
    }


    return EXIT_SUCCESS;
}