#ifndef RAINDROP_HPP
#define RAINDROP_HPP
#include <SFML/Graphics.hpp>

class RainDrop{

	public:

		RainDrop();
		~RainDrop();

		float getRainSpeed();
		sf::Vector2f getRainOrigin();
		sf::Vector2f getRainPosition();
		float getRainAlpha();
		float getRainRotation();
			
		void setRainSpeed(float rainSpeed);
		void setRainOrigin(sf::Vector2f origin);
		void setRainPosition(sf::Vector2f position);
		void setRainRotation(float angle);

		void update(sf::RenderWindow &Window);
		void draw(sf::RenderWindow &Window);

		static void initialize();

	private:
		float rainSpeed;
		float rainAlpha;
		float dx, dy;
		float angle;

		sf::Sprite rainSprite;
		sf::Texture rainText;	
		static sf::Texture rainTexture;


};

#endif