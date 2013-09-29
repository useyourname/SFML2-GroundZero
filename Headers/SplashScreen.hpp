#ifndef SPLASHSCREEN_HPP
#define SPLASHSCREEN_HPP
#include <SFML/Graphics.hpp>
#include "../Headers/GameScreen.hpp"

class SplashScreen: public GameScreen{
  public:
    SplashScreen();
    SplashScreen(std::string splashScreen, std::string gameray = "gaMeRaY", std::string productions = "productions");
    ~SplashScreen();

    void loadContent();
    void unloadContent();
    void handleEvent(const sf::Event event);
    void update(sf::RenderWindow &Window);
    void draw(sf::RenderWindow &Window);
    void display(sf::RenderWindow &Window);

    void setFont(std::string filename); 

  private:
    sf::Text text;
    sf::Text gamerayText;
    sf::Text productionsText;
    sf::Font font;

    std::string gameray;
    std::string productions; 
    std::string splashScreen;
};
#endif
