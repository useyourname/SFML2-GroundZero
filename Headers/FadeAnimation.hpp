#ifndef FADEANIMATION_HPP
#define FADEANIMATION_HPP
#include "Animation.hpp"

class FadeAnimation: public Animation{
	public:
		FadeAnimation();
		~FadeAnimation();
		void loadContent(std::string textBeforeConversion, sf::Texture texture, sf::Vector2f position);
		void unloadContent();
		void fadeScreenSwitch(GameScreen *currentScreen, GameScreen *newScreen);
		void draw(sf::RenderWindow &Window);
		void fader(sf::RectangleShape &continuousFade, sf::Vector2f position);
		void fadeOut(sf::RectangleShape &fadeOut, sf::Vector2f position);
		void fadeIn(sf::RectangleShape &fadeIn, sf::Vector2f position);

		//accessors
		float getFadeSpeed();
		float getFadeOutSpeed();
		float getFadeInSpeed();
		float getAlpha();
		bool getIncrease();

		//mutators
		void setFadeSpeed(float fadeSpeed);
		void setFadeOutSpeed(float fadeOutSpeed);
		void setFadeInSpeed(float fadeInSpeed);
		void restoreDefault();
		void restoreDefaultFadeSpeeds();
		void setAlpha(float alpha);
		void setIncrease(bool increase);

	protected:

	private:
		bool increase;

		float fadeSpeed;
		float fadeOutSpeed;
		float fadeInSpeed;
		float alpha;

		sf::RectangleShape fade;
};
#endif