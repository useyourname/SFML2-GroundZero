#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <SFML/Graphics.hpp>

class Character{
	public:

		Character();
		~Character();

		void draw(sf::RenderWindow &Window);
		void move(sf::Vector2f offset);
		void move(float x, float y);
		void rotate(float angle);

		float dtheta();
		float dx();
		float dy();
		float getAngle();
		float getAngularSpeed();
		sf::Color getColor();
		float getCosAngle();
		sf::FloatRect getGlobalBounds();
		sf::FloatRect getLocalBounds();
		float getLinearSpeed();
		sf::Vector2f getOrigin();
		sf::Vector2f getPosition();
		float getRadius();
		float getRotation();
		float getSinAngle();

		void setAlpha(float alpha);
		void setAngle(float angle);
		void setAngularSpeed(float angularSpeed);
		void setColor(sf::Color color);
		void setLinearSpeed(float linearSpeed);
		void setOrigin(sf::Vector2f origin);
		void setOrigin(float x, float y);
		void setPosition(sf::Vector2f position);
		void setPosition(float x, float y);
		void setRotation(float angle);

	private:

		sf::Texture playerTexture;
		sf::Sprite playerSprite;

		float linearSpeed;
		float angularSpeed;
		float angle;
		float cosAngle;
		float sinAngle;	
};

#endif