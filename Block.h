#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


class Block : public sf::Drawable
{
    public:
        Block(float x, float y);
        Vector2f getPosition();
        void update();
        float left();
        float right();
        float top();
        float bottom();


    private:
    RectangleShape block;
    const float blockWidth{60.0f};
    const float blockHeight{40.0f};
    void draw(RenderTarget& target, RenderStates state) const override;
};
