#include "../Headers/InputManager.hpp"
#include "../Headers/ScreenManager.hpp"

InputManager::InputManager(){

}

InputManager::~InputManager(){

}

bool InputManager::keyPressed(sf::Keyboard::Key key){
  if(ScreenManager::getInstance().event.type == sf::Event::KeyPressed && ScreenManager::getInstance().event.key.code == key) return true;
  return false;
}//end of keyPressed

bool InputManager::keyPressed(std::vector<sf::Keyboard::Key> keys){
  for(int i = 0; i < keys.size(); i++)
    if(this->keyPressed(keys[i])) return true;  
  return false;
}//end of keyPressed(vector)

bool InputManager::keyReleased(sf::Keyboard::Key key){
  if(ScreenManager::getInstance().event.type == sf::Event::KeyPressed && ScreenManager::getInstance().event.key.code == key) return true;
  return false;
}//end of keyReleased(int)

bool InputManager::keyReleased(std::vector<sf::Keyboard::Key> keys){
  for(int i = 0; i < keys.size(); i++)
    if(keyReleased(keys[i])) return true;
  return false;
}//end of keyReleased(vector)

bool InputManager::keyDown(sf::Keyboard::Key key){
  if(sf::Keyboard::isKeyPressed(key)) return true;
  return false;
}//end of keyDown(window, int key)

bool InputManager::keyDown(std::vector<sf::Keyboard::Key> keys){
  for(int i = 0; i < keys.size(); i++)
    if(sf::Keyboard::isKeyPressed(keys[i])) return true;
  return false;
}//end of keyDown(render window, vector <int>)
