#include <assert.h>
#include "../Headers/GameScreen.hpp"
#include "../Headers/InputManager.hpp"
#include "../Headers/ScreenManager.hpp"
#include "../Headers/Animation.hpp"

  GameScreen::GameScreen(){
    fadeAlpha = 0.f;
    fade.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
    fade.setFillColor(sf::Color(0.f, 0.f, 0.f, 255.f * fadeAlpha));
  }

  GameScreen::~GameScreen(){

  }

  void GameScreen::loadContent(){

  }//end of loadContent()

  void GameScreen::unloadContent(){
    input = NULL;
    keys.clear();
  }//end of unloadContent()
  
  void GameScreen::handleEvent(const sf::Event){

  }//end of handleEvent(event)
  
  void GameScreen::update(sf::RenderWindow &Window){

  }//end of update()

  void GameScreen::draw(sf::RenderWindow &Window){

  }//end of draw(sf::RenderWindow &Window)

  void GameScreen::display(sf::RenderWindow &Window){

  }//end of display(&Window)

  //accessors

  float GameScreen::getFadeAlpha(){
    return fadeAlpha;
  }//end of getFadeAlpha()*/

  sf::RectangleShape& GameScreen::getFadeRect(){
    return fade;
  }

  //mutators
  void GameScreen::setFadeAlpha(float fadeAlpha){
    this->fadeAlpha = fadeAlpha;
  }//end of setFadeAlpha(float alpha)*/
