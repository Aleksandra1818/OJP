#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"
#include <iostream>
#include <cstdlib>
 using namespace sf;
 using namespace std;


 vector<int>life;

 template <typename Object1, typename Object2> bool collision(Object1& a, Object2& b)
 {
     return a.right() >= b.left() && a.left() <= b.right() && a.bottom() >= b.top() && a.top() <= b.bottom();
 }

 bool collision_handle(Paddle& paddle, Ball& ball, Sound& sound)
 {

     if(!collision(paddle,ball)) return false;

     ball.bounce_up();
     sound.play();
     if(ball.getPosition().x < paddle.getPosition().x) ball.bounce_left();
     else if(ball.getPosition().x > paddle.getPosition().x) ball.bounce_right();
 }

 bool collision_handle_with_block(Ball& ball, Block& block)
 {

     if(!collision(ball,block)) return false;

     if(ball.getPosition().x < block.getPosition().x && (ball.getPosition().y > block.getPosition().y))
        {
            block.update();
            ball.bounce_down();
            ball.bounce_left();

            }
     else if(ball.getPosition().x > block.getPosition().x && (ball.getPosition().y > block.getPosition().y))
        {
            block.update();
            ball.bounce_down();
            ball.bounce_right();
            }
        else if(ball.getPosition().x < block.getPosition().x && ball.getPosition().y < block.getPosition().y)
        {
            block.update();
            ball.bounce_up();
            ball.bounce_left();
            }
        else if(ball.getPosition().x > block.getPosition().x && ball.getPosition().y < block.getPosition().y)
        {
            block.update();
            ball.bounce_up();
            ball.bounce_right();
            }

 }

int main()
{

    Ball ball(400,300);
    Paddle paddle(400,580);
    Block block(100,100);
    Block block2(165,100);
    Block block3(230,100);
    Block block4(295,100);
    Block block5(360,100);
    Block block6(425,100);
    Block block7(490,100);
    Block block8(135,145);
    Block block9(200,145);
    Block block10(265,145);
    Block block11(330,145);
    Block block12(395,145);
    Block block13(155,190);
    Block block14(220,190);

    RenderWindow window{VideoMode(800, 600), "Magic_ball", Style::Fullscreen};
    window.setMouseCursorVisible(false);
    Texture tekstura;
    tekstura.loadFromFile("niebo.jpg");
    SoundBuffer buffer;
    buffer.loadFromFile("Startup.wav");
    Sound sound;
    sound.setBuffer(buffer);
    Font font;
    font.loadFromFile("arial.ttf");


    window.setFramerateLimit(60);

    while(window.isOpen())
    {
        Event zdarzenie;
        window.clear();
        Sprite stlo(tekstura);

        while(window.pollEvent(zdarzenie))
        {
            if(zdarzenie.type==sf::Event::Closed) window.close();
            if(zdarzenie.type==sf::Event::KeyPressed && zdarzenie.key.code==sf::Keyboard::Escape) window.close();
            if(zdarzenie.type==sf::Event::MouseButtonPressed &&zdarzenie.mouseButton.button==sf::Mouse::Middle) window.close();
        }

        ball.update();
        paddle.update();
        window.draw(stlo);
        collision_handle(paddle,ball,sound);
        collision_handle_with_block(ball,block);
        collision_handle_with_block(ball,block2);
        collision_handle_with_block(ball,block3);
        collision_handle_with_block(ball,block4);
        collision_handle_with_block(ball,block5);
        collision_handle_with_block(ball,block6);
        collision_handle_with_block(ball,block7);
        collision_handle_with_block(ball,block8);
        collision_handle_with_block(ball,block9);
        collision_handle_with_block(ball,block10);
        collision_handle_with_block(ball,block11);
        collision_handle_with_block(ball,block12);
        collision_handle_with_block(ball,block13);
        collision_handle_with_block(ball,block14);
        window.draw(block);
        window.draw(block2);
        window.draw(block3);
        window.draw(block4);
        window.draw(block5);
        window.draw(block6);
        window.draw(block7);
        window.draw(block8);
        window.draw(block9);
        window.draw(block10);
        window.draw(block11);
        window.draw(block12);
        window.draw(block13);
        window.draw(block14);
        window.draw(ball);
        window.draw(paddle);

        if(ball.getPosition().y > paddle.getPosition().y)
            {

                Text tekst("-1 zycie",font);
                tekst.setCharacterSize(40);
                tekst.setStyle(sf::Text::Regular);
                tekst.setFillColor(sf::Color::Red);
                window.draw(tekst);
                life.push_back(1);
                cout << life.size();

                }
        if(life.size()/7==3) {
            Text tekst2("THE END",font);
            tekst2.setCharacterSize(60);
            tekst2.setStyle(sf::Text::Bold);
            tekst2.setFillColor(sf::Color::White);
            window.draw(tekst2);
            }

        window.display();
    }
    life.clear();



    return EXIT_SUCCESS;
}
