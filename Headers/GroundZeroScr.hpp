#ifndef GROUNDZEROSCR_HPP
#define GROUNDZEROSCR_HPP
#include <SFML/Audio.hpp>
#include "../Headers/GameScreen.hpp"
#include "../Headers/Character.hpp"


class GroundZeroScr : public GameScreen{

	public:
		GroundZeroScr();
		~GroundZeroScr();

	    void loadContent();
	    void unloadContent();
	    void handleEvent(const sf::Event event);
	    void update(sf::RenderWindow &Window);
	    void draw(sf::RenderWindow &Window);
	    void display(sf::RenderWindow &Window);
	    float distance(sf::Vector2f a, sf::Vector2f b);
	    void setEnemyPosition();
	private:

		sf::Texture backGroundTexture;
		sf::Sprite backGroundSprite;

		sf::Texture baseTexture;
		sf::Sprite baseSprite;
		sf::CircleShape baseCircle;

		Character player;
		Character enemy;

		sf::Music mgs3caution;
};
#endif