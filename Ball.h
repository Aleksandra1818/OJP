#include <SFML/Graphics.hpp>
using namespace sf;

class Ball : public sf::Drawable
{
public:
    Ball(float x, float y);
    //Ball() = delete; //usuwamy konstruktor "typowy"
    //~Ball() = default; //destruktor domyslnny
    void update();
    float bounce_up();
    float bounce_down();
    float bounce_left();
    float bounce_right();
    float left();
    float right();
    float top();
    float bottom();
    Vector2f getPosition();



private:
    CircleShape ball;
    const float radius{11.0f};
    const float ball_velocity{4.0f};
    Vector2f velocity{ball_velocity, ball_velocity};
    void draw(RenderTarget& target, RenderStates state) const override;
};
