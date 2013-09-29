#include <assert.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Headers/ScreenManager.hpp"
#include "../Headers/SplashScreen.hpp"
#include "../Headers/TitleScreen.hpp"
#include "../Headers/GameScreen.hpp"
using namespace std;

int main(){
  //main function variables
  bool enableKeyRepeat = false;
  sf::RenderWindow Window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32),"Hulq", sf::Style::None);
  Window.setMouseCursorVisible(false);
  Window.clear(sf::Color(0, 0, 0));
  Window.setFramerateLimit(60);
  Window.setKeyRepeatEnabled(enableKeyRepeat);

  ScreenManager::getInstance().initialize();
  ScreenManager::getInstance().loadContent();

  sf::Clock clock;
while(Window.isOpen()){
    ScreenManager::getInstance().setInEvent(false);
    while(Window.pollEvent(ScreenManager::getInstance().event)){
      ScreenManager::getInstance().setInEvent(true);
      if(ScreenManager::getInstance().event.type == sf::Event::Closed)
        Window.close();
      if(ScreenManager::getInstance().event.key.code == sf::Keyboard::Escape)
        Window.close();
      else
        ScreenManager::getInstance().handleEvent(ScreenManager::getInstance().event);
    }//end of while Poll event
    
    Window.clear(sf::Color(0, 0, 0)); 
    ScreenManager::getInstance().update(Window);
    ScreenManager::getInstance().draw(Window);
    Window.display();
    ScreenManager::getInstance().timeBetwFrame = clock.restart().asSeconds();

  }//end of while isOpen
  return 0;
}
