#ifndef ANIMATION_HPP
#define ANIMATION_HPP
#include <SFML/Graphics.hpp>
#include <string>

class GameScreen;

class Animation{
	public:
	Animation();
	virtual ~Animation();

	virtual void loadContent(std::string text, sf::Texture texture, sf::Vector2f position);
	virtual void unloadContent();
	virtual void update(sf::RenderWindow &Window, GameScreen *currentScreen, GameScreen *newScreen);
	virtual void draw(sf::RenderWindow &Window);

	void activate(); //activates the animation
	void deactivate(); //deactivates the animation

	bool isActive();

	protected:
	bool active;

	sf::IntRect sourceRect;
	sf::Vector2f position;
	sf::Sprite sprite;
	sf::Text text;
	sf::Color textColor;
	sf::Texture texture; 
	std::string textBeforeConversion; 
};
#endif