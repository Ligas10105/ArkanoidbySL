#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "Palette.h"
#include "Block.h"


using namespace std;
using namespace sf;

template<class T1, class T2>
bool isintersecting(T1 &a, T2 &b) {
    return a.right() >= b.left() && a.left() <= b.right() && a.bottom() >= b.top() && a.top() <= b.bottom();
}

bool collisionTest(Palette &palette, Ball &ball) {
    if (!isintersecting(palette, ball)) return false;
    ball.moveUp();

    if (ball.getPosition().x < palette.getPosition().x) {
        ball.moveLeft();
    } else if (ball.getPosition().x > palette.getPosition().x) {
        ball.moveRight();
    }
}

bool collisionTest(Block &block, Ball &ball) {
    if (isintersecting(block, ball)) {
        block.destroy();

        float overlapLeft{ball.right() - block.left()};
        float overlapRight{ball.right() - block.left()};
        float overlapTop{ball.bottom() - ball.top()};
        float overlapBottom{block.bottom() - ball.top()};

        bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
        bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

        float minOverlapX{ballFromLeft ? overlapLeft : overlapRight};
        float minOverlapY{ballFromTop ? overlapTop : overlapBottom};

        if (abs(minOverlapX) < abs(minOverlapY)) {
            ballFromLeft ? ball.moveLeft() : ball.moveRight();
        } else {
            ballFromTop ? ball.moveUp() : ball.moveDown();
        }
    }
}

int main() {
    Ball ball(400, 300);
    Palette palette(400, 550);
    RenderWindow window{VideoMode(800, 600), "ArkanoidbySL"};
    window.setFramerateLimit(60);
    Event event;
    unsigned blocksX{10}, blocksY{4}, blockWidth{60}, blockHeight{20};

    vector<Block> blocks;

    for (int i = 0; i < blocksY; i++) {
        for (int j = 0; j < blocksX; j++) {
            blocks.emplace_back((j + 1) * (blockWidth + 10), (i + 2) * (blockHeight + 5), blockWidth, blockHeight);
        }
    }
    while (true) {
        window.clear(Color::Black);
        window.pollEvent(event);

        if (event.type == Event::Closed) {
            window.close();
            break;
        }
        ball.update();
        palette.update();
        collisionTest(palette, ball);

        for(auto& block: blocks) if(collisionTest(block, ball)) break;


        window.draw(ball);
        window.draw(palette);


        for (auto &block: blocks)
            window.draw(block);

        window.display();
    }


    return EXIT_SUCCESS;
}