#include "../Headers/FadeAnimation.hpp"
#include "../Headers/ScreenManager.hpp"
#include <assert.h>

FadeAnimation::FadeAnimation(){
	fade.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
    fade.setFillColor(sf::Color(0,0,0,0));
    fadeSpeed = fadeInSpeed = fadeOutSpeed = 1.f;
    increase = true;
	alpha = 0.f;
}//end of FadeAnimation()*/

FadeAnimation::~FadeAnimation(){

}//end of ~FadeAnimation()*/

void FadeAnimation::loadContent(std::string textBeforeConversion, sf::Texture texture, sf::Vector2f position){
	Animation::loadContent(textBeforeConversion, texture, position);
}//end of loadContent()*/

void FadeAnimation::unloadContent(){

}//end of unloadContent()*/

void FadeAnimation::fadeScreenSwitch(GameScreen *currentScreen, GameScreen *newScreen){
	if(ScreenManager::getInstance().inTransition()){
		if(increase){
			alpha += fadeSpeed * (float)(ScreenManager::getInstance().timeBetwFrame);
		}
		if(!increase){
			alpha -= fadeSpeed * (float)(ScreenManager::getInstance().timeBetwFrame);
		}

		if(alpha >= 1.f){
			increase = false;
			assert(newScreen);
			ScreenManager::getInstance().screenSwitch(newScreen);
			alpha = 1.f;
		}
		else if(alpha < 0.f){
			alpha = 0.f;
			increase = true;	
			ScreenManager::getInstance().setTransition(false);
			restoreDefault();
			ScreenManager::getInstance().restartClock();
		}
	}//end of if(inTransition)*/
	fade.setFillColor(sf::Color(0.f, 0.f, 0.f, 255.f * alpha)); //alpha value is scaled up by 255
}//end of update()*/


void FadeAnimation::draw(sf::RenderWindow &Window){
	Window.draw(fade);	
}//end of draw()*/

void FadeAnimation::fader(sf::RectangleShape &continuousFade, sf::Vector2f position){
	if(ScreenManager::getInstance().inFader()){
		continuousFade.setPosition(position);
		if(increase){
			alpha += fadeOutSpeed * ScreenManager::getInstance().timeBetwFrame;
		}
		if(!increase){
			alpha -= fadeInSpeed * ScreenManager::getInstance().timeBetwFrame;
		}

		if(alpha >= 1.f){
			increase = false;
			alpha = 1.f;
		}
		else if(alpha < 0.f){
			increase = true;
			alpha = 0.f;
		}
		continuousFade.setFillColor(sf::Color(0.f, 0.f, 0.f, 255.f * alpha)); //alpha value is scaled up by 255
	}
}//end of fadeIn(sf::RectangleShape)*/

void FadeAnimation::fadeOut(sf::RectangleShape &fadeOut, sf::Vector2f position){
	if(ScreenManager::getInstance().inFadeOut()){
		increase = true;
		fade.setPosition(position);
		alpha += fadeOutSpeed * ScreenManager::getInstance().timeBetwFrame;

		if(alpha >= 1.f){
			alpha = 1.f;
			ScreenManager::getInstance().setFadeOut(false);
			restoreDefault();
		}
		fadeOut.setFillColor(sf::Color(0.f, 0.f, 0.f, 255.f * alpha));
	}
}//end of fadeOut*/

void FadeAnimation::fadeIn(sf::RectangleShape &fadeIn, sf::Vector2f position){
	if(ScreenManager::getInstance().inFadeIn()){
		increase = false;
		fade.setPosition(position);
		alpha -= fadeInSpeed * ScreenManager::getInstance().timeBetwFrame;

		if(alpha < 0.f){
			alpha = 0.f;
			ScreenManager::getInstance().setFadeIn(false);
			restoreDefault();
			ScreenManager::getInstance().restartClock();
		}	
		fade.setFillColor(sf::Color(0.f, 0.f, 0.f, 255.f * alpha));
	}
}//end of fadeIn()*/

//accessors
float FadeAnimation::getFadeSpeed(){
 return fadeSpeed;
}

float FadeAnimation::getFadeOutSpeed(){
	return fadeOutSpeed;
}

float FadeAnimation::getFadeInSpeed(){
	return fadeInSpeed;
}

float FadeAnimation::getAlpha(){
	return alpha;
}

bool FadeAnimation::getIncrease(){
	return increase;
}

//mutators
void FadeAnimation::setFadeSpeed(float fadeSpeed){
	this->fadeSpeed = fadeSpeed;
}

void FadeAnimation::setFadeOutSpeed(float fadeOutSpeed){
	this->fadeOutSpeed = fadeOutSpeed;
}

void FadeAnimation::setFadeInSpeed(float fadeInSpeed){
	this->fadeInSpeed = fadeInSpeed;
}

void FadeAnimation::setAlpha(float alpha){
	this->alpha = alpha;
}//end of setALpha(alpha)*/

void FadeAnimation::setIncrease(bool increase){
	this->increase = increase;
}//end of setIncrease(increase)*/

void FadeAnimation::restoreDefault(){
	fadeSpeed = fadeOutSpeed = fadeInSpeed = 1.f;
	increase = true;
	alpha = 0.f;
}//end of restoreDefault()*/

void FadeAnimation::restoreDefaultFadeSpeeds(){
	fadeSpeed = fadeOutSpeed = fadeInSpeed = 1.f;
}





