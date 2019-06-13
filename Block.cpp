#include "Block.h"

Block::Block(float x, float y)
{
    block.setPosition(x,y);
    block.setSize({this->blockWidth, this->blockHeight});
    block.setFillColor(Color::Red);
    block.setOutlineColor(Color::Blue);
    block.setOutlineThickness(2);
    block.setOrigin(blockWidth/2.0f, blockHeight/2.0f);


}
void Block::draw(RenderTarget& target,RenderStates state) const
{
    target.draw(this->block,state);
}

void Block::update()
{
    block.move(1000,900);
}
float Block::left()
{
    return this->block.getPosition().x - block.getSize().x/2.f;
}

float Block::right()
{
    return this->block.getPosition().x + block.getSize().x/2.f;
}

float Block::top()
{
    return this->block.getPosition().y - block.getSize().y/2.f;
}

float Block::bottom()
{
    return this->block.getPosition().y + block.getSize().y/2.f;
}

Vector2f Block::getPosition()
{
    return block.getPosition();
}
