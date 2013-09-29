#include <iostream>
#include <assert.h>
#include "../Headers/TitleScreen.hpp"
#include "../Headers/SplashScreen.hpp"
#include "../Headers/ScreenManager.hpp"
#include "../Headers/InputManager.hpp"
#include "../Headers/MenuScreen.hpp"
#include "../Headers/FadeAnimation.hpp"
using namespace std;

TitleScreen::TitleScreen(){
  this->animation = new FadeAnimation();
  animation->setAlpha(1.f);
  ScreenManager::getInstance().setFader(true);
}

TitleScreen::~TitleScreen(){
  if(animation){
    delete animation;
  }
  ScreenManager::getInstance().setFader(false);
  ScreenManager::getInstance().delay(0.13f);
}

void TitleScreen::loadContent(){
  if(!font.loadFromFile("Fonts/mgs4brush.ttf")) std::cout << "Error, can't find font 'mgs4brush.ttf'." << std::endl;
  if(!font2.loadFromFile("Fonts/zrnic.ttf")) std::cout << "Error, can't find font 'zrnic.ttf'." << std::endl; 
  string groundZero = "Ground Zero";
  string pressEnter = "Press Enter to Continue";
  int alpha = 200;
  spacing = 20.f;

  text.setFont(font);
  text.setStyle(sf::Text::Bold);
  text.setCharacterSize(100);
  text.setColor(sf::Color(255, 0, 0, alpha));
  text.setString(groundZero);
  text.setOrigin(text.getGlobalBounds().width/2.f, text.getGlobalBounds().height/2.f);
  text.setPosition(SCREEN_WIDTH/2.f, SCREEN_HEIGHT/2.f);

  text2.setFont(font2);
  text2.setCharacterSize(23);
  text2.setColor(sf::Color(255, 0, 0, alpha));
  text2.setString(pressEnter);
  text2.setOrigin(text2.getGlobalBounds().width/2.f, text2.getGlobalBounds().height/2.f);
  text2.setPosition(text.getPosition().x, text.getPosition().y + text2.getGlobalBounds().height + text.getLocalBounds().height - spacing);

  animation = new FadeAnimation();
  animation->setFadeInSpeed(animation->getFadeSpeed() / 1.8f);
  animation->setFadeOutSpeed(animation->getFadeSpeed() * 1.8f);

  if(!mgsmaintheme.openFromFile("Music/mgsmaintheme.ogg")) std::cout << "Failed to load 'mgsmaintheme.ogg'." << std::endl;
  mgsmaintheme.setLoop(true);
  mgsmaintheme.play();

  if(!revolverBuffer.loadFromFile("Music/mgssoundscheme/revolver.wav")){
    std::cout << "Failed to load 'revolver.wav'." << std::endl;
  }

  revolver.setBuffer(revolverBuffer);
  revolver.setLoop(false);

}//end of loadContent()

void TitleScreen::unloadContent(){

}//end of unloadContent()

void TitleScreen::handleEvent(const sf::Event event){
  if(input->keyPressed(sf::Keyboard::Return) && !ScreenManager::getInstance().inTransition()){
    ScreenManager::getInstance().setTransition(true);
    ScreenManager::getInstance().addScreen(new MenuScreen());
    animation->setFadeInSpeed(10.f);
    animation->setFadeOutSpeed(10.f);
    mgsmaintheme.stop();
    revolver.play();
  }
}//end of handleEvent(event)

void TitleScreen::update(sf::RenderWindow &Window){
  if(ScreenManager::getInstance().inFader()){
    spacing = 5.1f;
    continuousFade.setSize(sf::Vector2f(text2.getGlobalBounds().width, text2.getGlobalBounds().height));
    continuousFade.setOrigin(sf::Vector2f(continuousFade.getGlobalBounds().width/2.f, continuousFade.getGlobalBounds().height/2.f));
    animation->fader(continuousFade, sf::Vector2f(text2.getPosition().x, text2.getPosition().y + text2.getGlobalBounds().height - spacing));
  }
}//end of update()

void TitleScreen::draw(sf::RenderWindow &Window){
  text.setPosition(Window.getSize().x/2.f, Window.getSize().y/2.f);
  Window.draw(text);
  Window.draw(text2);
  Window.draw(continuousFade);
}//end of draw(sf::RenderWindow &window)
