#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


class Paddle : public sf::Drawable
{
    public:
        Paddle(float x, float y);
        //Paddle()=delete;
        //~Paddle()=default;
        Vector2f getPosition();
        void update();
        float left();
        float right();
        float top();
        float bottom();


    private:
    RectangleShape paddle;
    const float paddle_velocity{8.0f};
    const float paddleWidth{80.0f};
    const float paddleHeight{20.0f};
    Vector2f velocity{paddle_velocity, 0.f};
    void draw(RenderTarget& target, RenderStates state) const override;
};

