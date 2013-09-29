#include <assert.h>
#include <iostream>
#include "../Headers/SplashScreen.hpp"
#include "../Headers/TitleScreen.hpp"
#include "../Headers/ScreenManager.hpp"
#include "../Headers/InputManager.hpp"
#include "../Headers/FadeAnimation.hpp"

using namespace std;

SplashScreen::SplashScreen(){
  fade.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
  splashScreen = "gaMeRaY productions";
  gameray = "gaMeRaY";
  productions = " productions";
}

SplashScreen::SplashScreen(std::string splashScreen, std::string gameray, std::string productions)
: splashScreen(splashScreen)
{

}

SplashScreen::~SplashScreen(){
  ScreenManager::getInstance().splashScreenCounter++;
}

void SplashScreen::loadContent(){
  if(ScreenManager::getInstance().splashScreenCounter == 1){
    if(!font.loadFromFile("Fonts/Helvetica.dfont")) cout << "Error, can't find font 'Helvetica.dfont'." << endl;
    int alpha = 255;
    text.setFont(font);
    text.setCharacterSize(26);
    text.setColor(sf::Color(255, 255, 255, alpha));
    text.setString(splashScreen);
    text.setOrigin(text.getGlobalBounds().width/2.f, text.getGlobalBounds().height/2.f);
    text.setPosition(SCREEN_WIDTH/2.f, SCREEN_HEIGHT/2.f);

    gamerayText.setFont(font);
    gamerayText.setCharacterSize(26);
    gamerayText.setColor(sf::Color(114, 77, 255));
    gamerayText.setString(gameray);
    gamerayText.setOrigin(0.f, text.getGlobalBounds().height/2.f);
    gamerayText.setPosition(SCREEN_WIDTH/2.f - text.getLocalBounds().width/2.f, SCREEN_HEIGHT/2.f);

    productionsText.setFont(font);
    productionsText.setCharacterSize(26);
    productionsText.setColor(sf::Color::White);
    productionsText.setString(productions);
    productionsText.setOrigin(0.f, productionsText.getGlobalBounds().height/2.f);
    productionsText.setPosition(gamerayText.getPosition().x + gamerayText.getLocalBounds().width, SCREEN_HEIGHT/2.f);
  }

  else if(ScreenManager::getInstance().splashScreenCounter == 2){
    setFont("Fonts/Chalkduster.ttf");
    text.setFont(font);
    text.setStyle(sf::Text::Bold);
    text.setCharacterSize(30);
    text.setColor(sf::Color(255, 255, 255));
    text.setString(splashScreen);
    text.setOrigin(text.getGlobalBounds().width/2.f, text.getGlobalBounds().height/2.f);
    text.setPosition(SCREEN_WIDTH/2.f, SCREEN_HEIGHT/2.f);
  }

  else if(ScreenManager::getInstance().splashScreenCounter == 3){
    if(!font.loadFromFile("Fonts/mgs4maintitle.ttf")) std::cout << "Error, can't find 'mgs4maintitle.ttf'." << std::endl;
    text.setFont(font);
    text.setCharacterSize(41);
    text.setColor(sf::Color::Black);
    text.setString(splashScreen);
    text.setOrigin(text.getGlobalBounds().width/2.f, text.getGlobalBounds().height/2.f);
    text.setPosition(SCREEN_WIDTH/2.f, SCREEN_HEIGHT/2.f);
  }
}//end of loadContent()

void SplashScreen::unloadContent(){
  GameScreen::unloadContent();
}//end of unloadContent()

void SplashScreen::handleEvent(const sf::Event){
  if(input->keyPressed(sf::Keyboard::Return) && !ScreenManager::getInstance().inFadeIn() && (!ScreenManager::getInstance().getIncrease() || !ScreenManager::getInstance().inTransition())){
    if(!ScreenManager::getInstance().inTransition()){
      ScreenManager::getInstance().restartClock();
    }
    ScreenManager::getInstance().setTransition(true);      

    if(!ScreenManager::getInstance().getIncrease()){
      ScreenManager::getInstance().setIncrease(true);
    }  

    if(ScreenManager::getInstance().splashScreenCounter == 1){
      ScreenManager::getInstance().addScreen(new SplashScreen("rainhulq"));
    }
    else if(ScreenManager::getInstance().splashScreenCounter == 2){  
      ScreenManager::getInstance().addScreen(new SplashScreen("A RAIAN HUQ GAME"));
    }
    else if(ScreenManager::getInstance().splashScreenCounter == 3){
      ScreenManager::getInstance().addScreen(new TitleScreen());
    }
  }//end of if(keyPressed && in transition)*/

}//end of handleEvent(event)

void SplashScreen::update(sf::RenderWindow &Window){
  if(!(ScreenManager::getInstance().inTransition()) && !(ScreenManager::getInstance().inFadeIn()) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))){
    if(ScreenManager::getInstance().getElapsedTime() > 4.f){  

      if(!ScreenManager::getInstance().inTransition()){
        ScreenManager::getInstance().restartClock();
      }

      ScreenManager::getInstance().setTransition(true);

      if(ScreenManager::getInstance().splashScreenCounter == 1){
        ScreenManager::getInstance().addScreen(new SplashScreen("rainhulq"));
      }
      else if(ScreenManager::getInstance().splashScreenCounter == 2){  
        ScreenManager::getInstance().addScreen(new SplashScreen("A RAIAN HUQ GAME"));
      }
      else if(ScreenManager::getInstance().splashScreenCounter == 3){
        ScreenManager::getInstance().addScreen(new TitleScreen());
      }


    }
  }
}//end of update()

void SplashScreen::draw(sf::RenderWindow &Window){
  text.setPosition(Window.getSize().x/2.f, Window.getSize().y/2.f);
  if(ScreenManager::getInstance().splashScreenCounter == 1){
    Window.draw(gamerayText);
    Window.draw(productionsText);
  }
  else if(ScreenManager::getInstance().splashScreenCounter == 2){
    Window.draw(text);
  }
  else if(ScreenManager::getInstance().splashScreenCounter == 3){
    Window.clear(sf::Color(255, 255, 255));
    Window.draw(text);
  }//*/
}//end of draw(sf::RenderWindow &window)

void SplashScreen::display(sf::RenderWindow &Window){
  Window.display();
}

//mutators
void SplashScreen::setFont(std::string filename){
  assert(font.loadFromFile(filename));
}//end of setFont(font)*/
