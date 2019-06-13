#include "Ball.h"

Ball::Ball(float x, float y)
{
    ball.setPosition(x,y);
    ball.setRadius(this->radius);
    ball.setFillColor(Color::Yellow);
    ball.setOutlineColor(Color::White);
    ball.setOutlineThickness(3);
    ball.setOrigin(this->radius,this->radius);
}

void Ball::draw(RenderTarget& target,RenderStates state) const
{
    target.draw(this->ball,state);
}

void Ball::update()
{
    ball.move(this->velocity);

    if(this->left() < 0) {ball.setFillColor(Color::Blue); velocity.x=ball_velocity;}
    else if(this->right() > 800) {ball.setFillColor(Color::Green); velocity.x= -ball_velocity;}
    if(this->top() < 0) {ball.setFillColor(Color::Red); velocity.y=ball_velocity;}
    else if(this->bottom() > 600) {ball.setFillColor(Color::Yellow); velocity.y= -ball_velocity;}

}

float Ball::left()
{
    return this->ball.getPosition().x - ball.getRadius();
}

float Ball::right()
{
    return this->ball.getPosition().x + ball.getRadius();
}

float Ball::top()
{
    return this->ball.getPosition().y - ball.getRadius();
}

float Ball::bottom()
{
    return this->ball.getPosition().y + ball.getRadius();
}

float Ball::bounce_up()
{
    ball.setFillColor(Color::Yellow);
    this->velocity.y = - ball_velocity;
    return this->velocity.y;
}

float Ball::bounce_down()
{
    this->velocity.y =  ball_velocity;
    return this->velocity.y;
}
float Ball::bounce_left()
{
    this->velocity.x = -ball_velocity;
    return this->velocity.x;
}

float Ball::bounce_right()
{
    this->velocity.x = ball_velocity;
    return this->velocity.x;
}

Vector2f Ball::getPosition()
{
    return ball.getPosition();
}
