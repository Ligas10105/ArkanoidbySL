#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"


using namespace std;
using namespace sf;
int main()
{
    Ball ball(400, 300);
    RenderWindow window {VideoMode(800, 600), "ArkanoidbySL" };
    window.setFramerateLimit(60);
    Event event;
    while (true){
        window.clear(Color :: Black);
        window.pollEvent(event);

        if(event.type == Event :: Closed){
            window.close();
            break;
        }
        ball.update();
        window.draw(ball);
        window.display();
    }




    return EXIT_SUCCESS;
}