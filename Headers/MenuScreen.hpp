#ifndef MENUSCREEN_HPP
#define MENUSCREEN_HPP
#include <SFML/Audio.hpp>
#include "GameScreen.hpp"
#include "RainDrop.hpp"

class MenuScreen : public GameScreen{

	public:
		MenuScreen();
		~MenuScreen();
		void loadContent();
		void unloadContent();
	    void handleEvent(const sf::Event event);
		void update(sf::RenderWindow &Window);
		void draw(sf::RenderWindow &Window);
		void display(sf::RenderWindow &Window);

		float getRectangleSpeed();
		void setRectangleSpeed(float rectangleSpeed);
		void restoreDefaultRectangleSpeed();

	protected:

	private:
		enum{
			NEWGAME, LOADGAME, HIGHSCORES, OPTIONS, QUIT
		};

		//background image
		sf::Texture backGroundTexture;
		sf::Sprite backGroundSprite;

		//words on screen
		std::string newGame;
		std::string quit;

		int MENUSIZE;
		sf::Text menuText[5];
		std::string menuString[5];
	    sf::Font font;

	    //black rectangle
	    sf::RectangleShape blackRectangle;
	    float rectangleSpeed;

	    //variables for spacing and animation
	    float spacing;

	    //music and sounds
	    sf::Music mgs3startscreen;
	    sf::Music rain;
	    sf::Music quitgame;
	    sf::Sound menuScrollSound;
	    sf::SoundBuffer menuScrollBuffer;


	    //STATES
	    int index;
	    int prevIndex; //holds previous index
	    bool exitProgram;

	    RainDrop rainAnimation[100];
	    int DROPNUM; //number of raindrops
	};
#endif