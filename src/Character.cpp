#include <assert.h>
#include <cmath>
#include "../Headers/Character.hpp"
#include "../Headers/ScreenManager.hpp"

Character::Character(){
	assert(playerTexture.loadFromFile("Images/bluegreenisharrow.png"));
	playerSprite.setTexture(playerTexture);

	playerSprite.setScale(sf::Vector2f(0.03f, 0.03f));
	playerSprite.setColor(sf::Color(0, 204, 255, 200.f));	
	playerSprite.setOrigin(playerSprite.getLocalBounds().width/2.f, playerSprite.getLocalBounds().height/2.f);
	playerSprite.setPosition(0.f, 0.f);
	
	setRotation(360.f);
	setLinearSpeed(400.f);
	setAngularSpeed(400.f);
}

Character::~Character(){

}

void Character::draw(sf::RenderWindow &Window){
	Window.draw(playerSprite);
}

void Character::move(sf::Vector2f offset){
	playerSprite.move(offset);
}

void Character::move(float x, float y){
	playerSprite.move(sf::Vector2f(x, y));
}

void Character::rotate(float angle){
	setAngle(this->angle + angle);
}

//accessors
float Character::dtheta(){
	return getAngularSpeed() * ScreenManager::getInstance().timeBetwFrame;
}

float Character::dx(){
	return getLinearSpeed() * cosAngle * ScreenManager::getInstance().timeBetwFrame;
}

float Character::dy(){
	return getLinearSpeed() * sinAngle * ScreenManager::getInstance().timeBetwFrame;
}

float Character::getAngle(){
	return angle;
}

float Character::getAngularSpeed(){
	return angularSpeed;
}

sf::Color Character::getColor(){
	return playerSprite.getColor();
}

float Character::getCosAngle(){
	return cosAngle;
}

sf::FloatRect Character::getGlobalBounds(){
	return playerSprite.getGlobalBounds();
}

sf::FloatRect Character::getLocalBounds(){
	return playerSprite.getLocalBounds();
}

float Character::getLinearSpeed(){
	return linearSpeed;
}

sf::Vector2f Character::getOrigin(){
	return playerSprite.getOrigin();
}

sf::Vector2f Character::getPosition(){
	return playerSprite.getPosition();
}

float Character::getRadius(){
	return playerSprite.getGlobalBounds().width/2.f;
}

float Character::getRotation(){
	return playerSprite.getRotation();
}

float Character::getSinAngle(){
	return sinAngle;
}
//mutators

void Character::setAlpha(float alpha){
	setColor(sf::Color(getColor().r, getColor().g, getColor().b, alpha));
}

void Character::setAngle(float angle){
	if(angle > 360.f) angle -= 360;
	if(angle <= 0.f) angle += 360;
	this->angle = angle;
	playerSprite.setRotation(this->angle);
	cosAngle = cos(angle * M_PI/180);
	sinAngle = sin(angle * M_PI/180);
}

void Character::setAngularSpeed(float angularSpeed){
	this->angularSpeed = angularSpeed;
}

void Character::setColor(sf::Color color){
	playerSprite.setColor(color);
}

void Character::setLinearSpeed(float linearSpeed){
	this->linearSpeed = linearSpeed;
}

void Character::setOrigin(sf::Vector2f origin){
	playerSprite.setOrigin(origin);
}

void Character::setOrigin(float x, float y){
	playerSprite.setOrigin(x, y);
}

void Character::setPosition(sf::Vector2f position){
	playerSprite.setPosition(position);
}

void Character::setPosition(float x, float y){
	playerSprite.setPosition(x, y);
}

void Character::setRotation(float angle){
	setAngle(angle);
	playerSprite.setRotation(angle);
}
