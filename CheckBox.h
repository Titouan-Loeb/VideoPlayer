#include "AGUI.h"

class CheckBox : public AGUI
{
public:
	CheckBox(const sf::Texture& texture, const sf::IntRect& rect, const sf::Vector2f& pos, const bool& statee);
	~CheckBox();
	void draw(sf::RenderWindow& window);
	bool isMouseOn(const sf::Vector2i& mousePos, const SceneEvents::mouseEventType& mouseEvent);
	void setPosition(const sf::Vector2f& position);
	void setSize(const sf::Vector2f& size);
	const int getValue();
	void setValue(const int& value);

private:
	sf::Sprite _sprite;
	sf::IntRect _rect;
	sf::Vector2f _pos;
	bool _state;
};