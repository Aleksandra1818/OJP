#include "Paddle.h"

Paddle::Paddle(float x, float y)
{
    paddle.setPosition(x,y);
    paddle.setSize({this->paddleWidth, this->paddleHeight});
    paddle.setFillColor(Color::White);
    paddle.setOutlineColor(Color::Black);
    paddle.setOutlineThickness(3);
    paddle.setOrigin(paddleWidth/2.0f, paddleHeight/2.0f);


}
void Paddle::draw(RenderTarget& target,RenderStates state) const
{
    target.draw(this->paddle,state);
}

void Paddle::update()
{
    this->paddle.move(this->velocity);
    if(Keyboard::isKeyPressed(Keyboard::Key::Left)&& this->left()>0) velocity.x = -paddle_velocity;
    else if(Keyboard::isKeyPressed(Keyboard::Key::Right)&& this->right()<800) velocity.x = paddle_velocity;
    else velocity.x=0;

}
float Paddle::left()
{
    return this->paddle.getPosition().x - paddle.getSize().x/2.f;
}

float Paddle::right()
{
    return this->paddle.getPosition().x + paddle.getSize().x/2.f;
}

float Paddle::top()
{
    return this->paddle.getPosition().y - paddle.getSize().y/2.f;
}

float Paddle::bottom()
{
    return this->paddle.getPosition().y + paddle.getSize().y/2.f;
}
Vector2f Paddle::getPosition()
{
    return paddle.getPosition();
}
