#ifndef SCREENMANAGER_HPP
#define SCREENMANAGER_HPP

#define SCREEN_WIDTH 1300.f
#define SCREEN_HEIGHT 768.f

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

//forward declaration
class GameScreen;
class Animation;

class ScreenManager{
  public:
    ~ScreenManager();
    static ScreenManager& getInstance();

    void initialize();
    void loadContent();
    void handleEvent(const sf::Event event);
    void update(sf::RenderWindow &Window);
    void draw(sf::RenderWindow &Window);
    void display(sf::RenderWindow &Window);
    void addScreen(GameScreen *screen);
    void screenSwitch(GameScreen *screen); //deletes current screen and makes new screen the current screen

    int randNumGen(int lowerLimit, int upperLimit);

    bool inTransition(); //these functions tell us what is being called in the FadeAnimation class
    bool inFadeIn(); 
    bool inFadeOut();
    bool inFader();
    bool inEvent();
    float getScreenAlpha();
    bool getIncrease(); //this tells whether screen alpha would increase or decrease if the fading/transition flags were set to true
    float getFadeInSpeed();
    float getFadeOutSpeed();
    float getFadeSpeed();


    void setTransition(bool inTransition);
    void setFadeIn(bool fadeIn);
    void setFadeOut(bool fadeOut);
    void setFader(bool fader);
    void setInEvent(bool isEvent);
    void setIncrease(bool increase); //set how the alpha would change if the window went into transition/fading mode
    void setEnableKeyRepeat(bool enableKeyRebeat);
    void setFadeInSpeed(float fadeInSpeed);
    void setFadeOutSpeed(float fadeOutSpeed);
    void setFadeSpeed(float fadeSpeed);
    void restoreDefaultFadeSpeeds();

    void delay(float delayTime); 
    void startClock();
    float restartClock();
    float getElapsedTime();

    sf::Event event;
    float timeBetwFrame;
    int splashScreenCounter;

    sf::Clock stopWatch;
    
  private:
    GameScreen *currentScreen;
    GameScreen *nextScreen;
    Animation *animation;

    bool _inTransition;
    bool _fadeOut;
    bool _fadeIn;
    bool _fader;
    bool _inEvent;

    ScreenManager();
    ScreenManager(ScreenManager &ScreenManager);
    void operator=(ScreenManager &ScreenManager);
};

#endif
