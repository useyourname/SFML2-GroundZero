#include <cmath>
#include <assert.h>
#include <iostream>
#include "../Headers/RainDrop.hpp"
#include "../Headers/ScreenManager.hpp"

sf::Texture RainDrop::rainTexture;

void RainDrop::initialize(){
	assert(RainDrop::rainTexture.loadFromFile("Images/rain.png"));
}

RainDrop::RainDrop(){
	rainSpeed = ScreenManager::getInstance().randNumGen(6000, 9000);
	rainText.loadFromFile("Images/rain.png");
	rainSprite.setTexture(rainText);
	rainAlpha = 15.f;
	rainSprite.setColor(sf::Color(159, 197, 200, rainAlpha));

	setRainRotation(90.f);

	setRainOrigin(sf::Vector2f(rainSprite.getLocalBounds().width/2.f, rainSprite.getLocalBounds().height/2.f));
	setRainPosition(sf::Vector2f(ScreenManager::getInstance().randNumGen(0, 1367), 0.f - rainSprite.getLocalBounds().width/2.f));
	setRainRotation(ScreenManager::getInstance().randNumGen(70, 95));

}

RainDrop::~RainDrop(){
	
}

void RainDrop::update(sf::RenderWindow &Window){
	dx = ScreenManager::getInstance().timeBetwFrame * rainSpeed * cos(angle);
	dy = ScreenManager::getInstance().timeBetwFrame * rainSpeed * sin(angle);
	rainSprite.move(dx, dy);
	if(rainSprite.getPosition().y > SCREEN_HEIGHT + rainSprite.getLocalBounds().width){
		rainSprite.setPosition(sf::Vector2f(ScreenManager::getInstance().randNumGen(0, 1367), 0.f));
	}
}

void RainDrop::draw(sf::RenderWindow &Window){
	Window.draw(rainSprite);
}

//accessors
float RainDrop::getRainSpeed(){
	return rainSpeed;
}

sf::Vector2f RainDrop::getRainOrigin(){
	return rainSprite.getOrigin();
}

sf::Vector2f RainDrop::getRainPosition(){
	return rainSprite.getPosition();
}

float RainDrop::getRainAlpha(){
	return rainAlpha;
}

float RainDrop::getRainRotation(){
	return rainSprite.getRotation();
}

	
void RainDrop::setRainSpeed(float rainSpeed){
	this->rainSpeed = rainSpeed;
}

void RainDrop::setRainOrigin(sf::Vector2f origin){
	rainSprite.setOrigin(origin);
}

void RainDrop::setRainPosition(sf::Vector2f position){
	rainSprite.setPosition(position);
}

void RainDrop::setRainRotation(float angle){
	this->angle = angle;
	rainSprite.setRotation(angle);
}




