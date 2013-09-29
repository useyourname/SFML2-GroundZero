#include <assert.h>
#include <string>
#include "../Headers/ScreenManager.hpp"
#include "../Headers/SplashScreen.hpp"
#include "../Headers/TitleScreen.hpp"
#include "../Headers/GameScreen.hpp"
#include "../Headers/Animation.hpp"
#include "../Headers/FadeAnimation.hpp"

static unsigned long x=123456789, y=362436069, z=521288629; //numbers used for xorshf random number generator
ScreenManager::ScreenManager(){
  
}//ctor

ScreenManager::~ScreenManager(){
  if(currentScreen) delete currentScreen; 
  if(animation) delete animation;
  nextScreen = NULL; 
}//dtor

void ScreenManager::addScreen(GameScreen *screen){
  if(nextScreen && nextScreen != currentScreen) delete nextScreen;
  nextScreen = screen;
}//end of addScreen(GameScreen *screen)

void ScreenManager::draw(sf::RenderWindow &Window){
  currentScreen->draw(Window);
  animation->draw(Window);
}//end of draw(sf::RenderWindow &window)

ScreenManager& ScreenManager::getInstance(){
  static ScreenManager instance;
  return instance;
}//end of getInstance()

void ScreenManager::handleEvent(const sf::Event event){
  currentScreen->handleEvent(event);
}//end of handleEvent(event)

void ScreenManager::initialize(){
  currentScreen = new SplashScreen();
  animation = new FadeAnimation();
  assert(dynamic_cast<FadeAnimation*>(animation));
  static_cast<FadeAnimation*>(animation)->setAlpha(1.f);
  static_cast<FadeAnimation*>(animation)->setIncrease(false);
  _inTransition = false;
  _fader = false;
  _fadeOut = false;
  _fadeIn = true; 

  splashScreenCounter = 1;
}//end of initialize()

void ScreenManager::loadContent(){
  currentScreen->loadContent();
}//end of loadContent()

void ScreenManager::update(sf::RenderWindow &Window){
  currentScreen->update(Window);
  assert(dynamic_cast<FadeAnimation*>(animation));
  if(ScreenManager::getInstance().inTransition()){
    static_cast<FadeAnimation*>(animation)->fadeScreenSwitch(currentScreen, nextScreen);
  }
  if(ScreenManager::getInstance().inFadeOut()){
    static_cast<FadeAnimation*>(animation)->fadeOut(currentScreen->getFadeRect(), sf::Vector2f(0,0));
  }
  if(ScreenManager::getInstance().inFadeIn()){
    static_cast<FadeAnimation*>(animation)->fadeIn(currentScreen->getFadeRect(), sf::Vector2f(0, 0));
  }
}//end of update()*/



void ScreenManager::delay(float delayTime){
  sf::Clock delayClock;
  delayClock.restart();
  while(delayClock.getElapsedTime().asSeconds() < delayTime);
}//end of delay(delayTime);

void ScreenManager::startClock(){
  stopWatch.restart();
}

float ScreenManager::restartClock(){
  return stopWatch.restart().asSeconds();
}

float ScreenManager::getElapsedTime(){
  return stopWatch.getElapsedTime().asSeconds();
}

void ScreenManager::display(sf::RenderWindow &Window){
  currentScreen->display(Window);
}//end of display(Window)*/

// xorshf random number generator
int ScreenManager::randNumGen(int lowerLimit, int upperLimit){
  unsigned long t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;

  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;

  return z % (upperLimit - lowerLimit + 1) + lowerLimit;
}

void ScreenManager::screenSwitch(GameScreen *screen){
  if(inTransition()){ //FadeAnimation will take care of setting the transition flag to false once transition is done
    assert(screen && currentScreen);
    if(currentScreen != screen){
      delete currentScreen;
      nextScreen = screen;
      currentScreen = screen;
      currentScreen->loadContent();
    }
  }
}//end of screenTransition()*/

//accessors
float ScreenManager::getScreenAlpha(){
  assert(dynamic_cast<FadeAnimation*>(animation));
  return static_cast<FadeAnimation*>(animation)->getAlpha();
}

bool ScreenManager::getIncrease(){
  assert(dynamic_cast<FadeAnimation*>(animation));
  return static_cast<FadeAnimation*>(animation)->getIncrease();
}

bool ScreenManager::inTransition(){
  return _inTransition;
}//end of inTransition()*.

bool ScreenManager::inFadeIn(){
  return _fadeIn;
}
bool ScreenManager::inFadeOut(){
  return _fadeOut;
}
bool ScreenManager::inFader(){
  return _fader;
}

bool ScreenManager::inEvent(){
  return _inEvent; 
}

float ScreenManager::getFadeInSpeed(){
  assert(dynamic_cast<FadeAnimation*>(animation));
  return static_cast<FadeAnimation*>(animation)->getFadeInSpeed();
}

float ScreenManager::getFadeOutSpeed(){
  assert(dynamic_cast<FadeAnimation*>(animation));
  return static_cast<FadeAnimation*>(animation)->getFadeInSpeed();
}

float ScreenManager::getFadeSpeed(){
  assert(dynamic_cast<FadeAnimation*>(animation));
  return static_cast<FadeAnimation*>(animation)->getFadeInSpeed();
}


//mutators
void ScreenManager::setInEvent(bool inEvent){
  _inEvent = inEvent;
}

void ScreenManager::setFadeIn(bool fadeIn){
  _fadeIn = fadeIn;
}

void ScreenManager::setFadeOut(bool fadeOut){
  _fadeOut = fadeOut;
}

void ScreenManager::setFader(bool fader){
  _fader = fader;
}

void ScreenManager::setTransition(bool inTransition){
  _inTransition = inTransition;
}//end of setTransition()*/

void ScreenManager::setIncrease(bool increase){
  assert(dynamic_cast<FadeAnimation*>(animation));
  static_cast<FadeAnimation*>(animation)->setIncrease(increase);
}

void ScreenManager::setFadeInSpeed(float fadeInSpeed){
  assert(dynamic_cast<FadeAnimation*>(animation));
  static_cast<FadeAnimation*>(animation)->setFadeInSpeed(fadeInSpeed);
}

void ScreenManager::setFadeOutSpeed(float fadeOutSpeed){
  assert(dynamic_cast<FadeAnimation*>(animation));
  static_cast<FadeAnimation*>(animation)->setFadeSpeed(fadeOutSpeed);
}

void ScreenManager::setFadeSpeed(float fadeSpeed){
  assert(dynamic_cast<FadeAnimation*>(animation));
  static_cast<FadeAnimation*>(animation)->setFadeSpeed(fadeSpeed);
}

void ScreenManager::restoreDefaultFadeSpeeds(){
  assert(dynamic_cast<FadeAnimation*>(animation));
  static_cast<FadeAnimation*>(animation)->restoreDefaultFadeSpeeds();
}
