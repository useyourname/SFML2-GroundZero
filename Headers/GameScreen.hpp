#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class InputManager;
class Animation;
class FadeAnimation;

class GameScreen{
  public:
    GameScreen();
    virtual ~GameScreen();

    virtual void loadContent();
    virtual void unloadContent();
    virtual void handleEvent(const sf::Event event);
    virtual void update(sf::RenderWindow &Window);
    virtual void draw(sf::RenderWindow &Window);
    virtual void display(sf::RenderWindow &Window);
    float getFadeAlpha();
    void setFadeAlpha(float fadeAlpha);

    sf::RectangleShape& getFadeRect();

  protected:
    std::vector<sf::Keyboard::Key> keys;
    InputManager *input; 
    float fadeAlpha;
    sf::RectangleShape fade;
};

#endif
