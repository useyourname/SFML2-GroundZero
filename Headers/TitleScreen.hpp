#ifndef TITLESCREEN_HPP
#define TITLESCREEN_HPP
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "../Headers/GameScreen.hpp"

class TitleScreen: public GameScreen{
  public:
    TitleScreen();
    ~TitleScreen();

    void loadContent();
    void unloadContent();
    void handleEvent(const sf::Event event);
    void update(sf::RenderWindow &Window);
    void draw(sf::RenderWindow &window);

  private:
    sf::Text text;
    sf::Text text2;

    sf::Font font;
    sf::Font font2;

    sf::Music mgsmaintheme;
    sf::Sound revolver;
    sf::SoundBuffer revolverBuffer;

    std::string splashScreen;

    float spacing;
    sf::RectangleShape continuousFade;

    FadeAnimation *animation;
};
#endif
