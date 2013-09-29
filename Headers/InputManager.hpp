#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP
#include <SFML/Window.hpp>

class InputManager{
    public:
      InputManager();
      ~InputManager();

      bool keyPressed(sf::Keyboard::Key key);
      bool keyPressed(std::vector<sf::Keyboard::Key> keys);

      bool keyReleased(sf::Keyboard::Key key);
      bool keyReleased(std::vector<sf::Keyboard::Key> keys);

      bool keyDown(sf::Keyboard::Key key);
      bool keyDown(std::vector<sf::Keyboard::Key> keys);
};

#endif
