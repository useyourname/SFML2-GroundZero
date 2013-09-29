#include <assert.h>
#include <iostream>
#include <cmath>
#include "../Headers/GroundZeroScr.hpp"
#include	 "../Headers/ScreenManager.hpp"

GroundZeroScr::GroundZeroScr(){

}

GroundZeroScr::~GroundZeroScr(){

}


void GroundZeroScr::loadContent(){
	//initialize music and sounds
	assert(mgs3caution.openFromFile("Music/mgs3caution.ogg"));	
	mgs3caution.setLoop(true);
	mgs3caution.play();

	assert(backGroundTexture.loadFromFile("Images/hextiles.jpg"));
	backGroundSprite.setTexture(backGroundTexture);

	assert(baseTexture.loadFromFile("Images/redcircle.gif"));
	baseSprite.setTexture(baseTexture);

	backGroundSprite.setScale(sf::Vector2f(SCREEN_WIDTH/backGroundTexture.getSize().x, SCREEN_HEIGHT/backGroundTexture.getSize().y));
	backGroundSprite.setOrigin(backGroundSprite.getLocalBounds().width/2.f, backGroundSprite.getLocalBounds().height/2.f);
	backGroundSprite.setPosition(SCREEN_WIDTH/2.f, SCREEN_HEIGHT/2.f);

	baseSprite.setScale(sf::Vector2f(1.3f, 1.3f));
	baseSprite.setOrigin(baseSprite.getLocalBounds().width/2.f, baseSprite.getLocalBounds().height/2.f);
	baseSprite.setPosition(backGroundSprite.getPosition());	

	baseCircle.setRadius(baseSprite.getGlobalBounds().width/2.f);
	baseCircle.setOrigin(baseCircle.getLocalBounds().width/2.f, baseCircle.getLocalBounds().height/2.f);
	baseCircle.setFillColor(sf::Color(255,255,255,0));
	baseCircle.setPosition(baseSprite.getPosition());

	player.setPosition(backGroundSprite.getPosition().x + baseSprite.getGlobalBounds().width/2.f + player.getGlobalBounds().width, backGroundSprite.getPosition().y);
	player.setAlpha(155.f);

	enemy.setOrigin(enemy.getPosition().x + enemy.getGlobalBounds().width/2.f, enemy.getPosition().y);
	enemy.setColor(sf::Color(119.f, 136.f, 153.f, 255.f));

	enemy.setPosition(0.f, 0.f);
	enemy.setRotation(0.f);

	//pseudo-randomly selects enemies position at the border of the screen
	setEnemyPosition();
}

void GroundZeroScr::unloadContent(){

}

void GroundZeroScr::handleEvent(const sf::Event event){

}//end of handleEvent(event)*/

void GroundZeroScr::update(sf::RenderWindow &Window){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		player.move(player.dx(), 0.f);
		if(distance(player.getPosition(), baseCircle.getPosition()) < baseCircle.getRadius() + 10.f){
			player.move(-1 * player.dx(), 0.f);
		}

		player.move(0.f, player.dy());
		if(distance(player.getPosition(), baseCircle.getPosition()) < baseCircle.getRadius() + 10.f){
			player.move(0.f, -1 * player.dy());
		}		
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		player.move(-1 * player.dx(), 0.f);
		if(distance(player.getPosition(), baseCircle.getPosition()) < baseCircle.getRadius() + 10.f){
			player.move(player.dx(), 0.f);
		}		

		player.move(0.f, -1 * player.dy());
		if(distance(player.getPosition(), baseCircle.getPosition()) < baseCircle.getRadius() + 10.f){
			player.move(0.f, player.dy());
		}		
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		player.rotate(-1 * player.dtheta());
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		player.rotate(player.dtheta());
	}

	//bounding box
	if(player.getPosition().x < -10.f){
		player.setPosition(SCREEN_WIDTH, player.getPosition().y);
	}

	if(player.getPosition().x > SCREEN_WIDTH + 10.f){
		player.setPosition(0.f, player.getPosition().y);
	}

	if(player.getPosition().y < -10.f){
		player.setPosition(player.getPosition().x, SCREEN_HEIGHT); 
	}

	if(player.getPosition().y > SCREEN_HEIGHT + 10.f){
		player.setPosition(player.getPosition().x, 0.f);
	}

	//enemy movement
	enemy.move(enemy.dx(), enemy.dy());
	if(enemy.getPosition().x < -10.f || enemy.getPosition().x > SCREEN_WIDTH + 10.f
	|| enemy.getPosition().y < -10.f || enemy.getPosition().y > SCREEN_HEIGHT + 10.f){
		setEnemyPosition();
	}

	//collision with enemy
	if(distance(player.getPosition(), enemy.getPosition()) < player.getRadius() 
		&& (  (fabsf(player.getRotation() - enemy.getRotation()) < 90.f)
		||    (fabsf(player.getRotation() - enemy.getRotation()) > 270.f) )){
		setEnemyPosition();
	}
}//end of update()*/

void GroundZeroScr::draw(sf::RenderWindow &Window){
	Window.draw(backGroundSprite);
	Window.draw(baseCircle);
	player.draw(Window);
	enemy.draw(Window);
	Window.draw(baseSprite);
}

void GroundZeroScr::display(sf::RenderWindow &Window){

}

//accessors
float GroundZeroScr::distance(sf::Vector2f a, sf::Vector2f b){
	return sqrtf(powf(fabsf(b.x - a.x), 2.f) + powf(fabsf(b.y - a.y), 2.f));
}

//mutators
void GroundZeroScr::setEnemyPosition(){
	//pseudo-randomly selects enemies position at the border of the screen
	int randX = ScreenManager::getInstance().randNumGen(0, 1);
	int randY = ScreenManager::getInstance().randNumGen(0, 1);

	//reset enemy rotation
	enemy.setRotation(0.f);
	if(randX){
		if(randY){
			enemy.setPosition(ScreenManager::getInstance().randNumGen(0, SCREEN_WIDTH), SCREEN_HEIGHT);
		}
		else{
			enemy.setPosition(SCREEN_WIDTH, ScreenManager::getInstance().randNumGen(0, SCREEN_HEIGHT));
		}
	}
	else{
		if(randY){
			enemy.setPosition(ScreenManager::getInstance().randNumGen(0, SCREEN_WIDTH), 0);
		}
		else{
			enemy.setPosition(0, ScreenManager::getInstance().randNumGen(0, SCREEN_HEIGHT));
		}
	}//*/

	// rotate to face center of the screen
	sf::Vector2f directionVector(baseCircle.getPosition().x - enemy.getPosition().x, enemy.getPosition().y - baseCircle.getPosition().y);
	float enemyRotation = (180.f/M_PI) * atan2(directionVector.y, directionVector.x);

	enemyRotation = 360.f - enemyRotation;
	enemy.rotate(enemyRotation);
	enemy.setLinearSpeed(100.f);

}

