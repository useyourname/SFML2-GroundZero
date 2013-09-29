#include <iostream>
#include <math.h>
#include <assert.h>
#include "../Headers/ScreenManager.hpp"
#include "../Headers/MenuScreen.hpp"
#include "../Headers/InputManager.hpp"
#include "../Headers/RainDrop.hpp"
#include "../Headers/GroundZeroScr.hpp"

MenuScreen::MenuScreen(){

}//end of MenuScreen()*/

MenuScreen::~MenuScreen(){

}//end of ~MenuScreen()*/

void MenuScreen::loadContent(){
	//initialize states
	index = 0;
	prevIndex = index;
	exitProgram = false;

	if(!backGroundTexture.loadFromFile("Images/groundzero.jpg")) std::cout << "Texture loading not successful\n"; 

	backGroundSprite.setTexture(backGroundTexture);
	backGroundSprite.setScale(sf::Vector2f(SCREEN_WIDTH/backGroundTexture.getSize().x, SCREEN_HEIGHT/backGroundTexture.getSize().y));

	if(!font.loadFromFile("Fonts/zrnic.ttf")) std::cout << "Error, can't find font." << std::endl;

	menuString[NEWGAME] = " New Game";
	menuString[LOADGAME] = " Load Game";
	menuString[HIGHSCORES] = " High Scores";
	menuString[OPTIONS] = " Options";
	menuString[QUIT] = " Exit";
	MENUSIZE = 5;

	//text initialization
    for(int i = 0; i < MENUSIZE; i++){
	    menuText[i].setFont(font);
	    menuText[i].setCharacterSize(23);
	    menuText[i].setColor(sf::Color(sf::Color::Black));
	    menuText[i].setString(menuString[i]); 
	    menuText[i].setOrigin(0, menuText[i].getLocalBounds().height/2.f);
    }//end of for(int i = 0; i < MENUSIZE; i++)*/

    menuText[NEWGAME].setColor(sf::Color::White); //black rectangle intially covers this so its white

    //set rectangle origin before setting position of text; the rectangles origin is NOT at its center
   	spacing = 8.5f; 
    menuText[NEWGAME].setPosition((0.38f) * SCREEN_WIDTH, (0.50f) * SCREEN_HEIGHT);
    for(int i = 1; i < MENUSIZE; i++){
    	menuText[i].setPosition(menuText[NEWGAME].getPosition().x, menuText[i - 1].getPosition().y + menuText[i].getLocalBounds().height + spacing);
    }//end of for(int i = 1; i < MENUSIZE; i++)*/


    //initializing black rectangle properties
   	blackRectangle.setOrigin(0, blackRectangle.getLocalBounds().height/2.f);
   	blackRectangle.setFillColor(sf::Color::Black);
   	blackRectangle.setSize(sf::Vector2f(1.4f * menuText[NEWGAME].getLocalBounds().width,menuText[NEWGAME].getCharacterSize())); 
   	blackRectangle.setPosition(menuText[NEWGAME].getPosition());
   	rectangleSpeed = 150.f;

   	//initializing music and sounds
   	assert(rain.openFromFile("Music/rain.ogg"));
   	assert(mgs3startscreen.openFromFile("Music/mgs3startscreen.ogg"));

   	rain.setLoop(true);
   	rain.setVolume(0.3f * rain.getVolume());
   	mgs3startscreen.setLoop(true);
   	rain.play();
   	mgs3startscreen.play();

   	assert(menuScrollBuffer.loadFromFile("Music/mgssoundscheme/mgsstartnav.wav"));
   	menuScrollSound.setBuffer(menuScrollBuffer);

   	assert(quitgame.openFromFile("Music/mgssoundscheme/quitgame.wav"));

	 //slight adjustments to origins
	 menuText[HIGHSCORES].setOrigin(0, menuText[HIGHSCORES].getLocalBounds().height/2.f - menuText[HIGHSCORES].getCharacterSize()/6.f);
	 menuText[OPTIONS].setOrigin(0, menuText[OPTIONS].getLocalBounds().height/2.f - menuText[OPTIONS].getCharacterSize()/6.f);
	 menuText[QUIT].setOrigin(0, menuText[QUIT].getLocalBounds().height/2.f - menuText[QUIT].getCharacterSize()/6.f);

	 menuText[HIGHSCORES].setPosition(menuText[HIGHSCORES].getPosition().x, menuText[HIGHSCORES].getPosition().y + menuText[HIGHSCORES].getCharacterSize()/100.f);
	 menuText[OPTIONS].setPosition(menuText[OPTIONS].getPosition().x, menuText[OPTIONS].getPosition().y + menuText[OPTIONS].getCharacterSize()/100.f);
	 menuText[QUIT].setPosition(menuText[QUIT].getPosition().x, menuText[QUIT].getPosition().y + menuText[QUIT].getCharacterSize()/100.f);

	 //rain animation initialization
	 DROPNUM = 100;
	 RainDrop::initialize();

}//end of loadContent()*/

void MenuScreen::unloadContent(){

}//end of unloadContent()*/

void MenuScreen::handleEvent(const sf::Event event){
	restoreDefaultRectangleSpeed();
	if(!ScreenManager::getInstance().inFadeOut()){
		if(input->keyPressed(sf::Keyboard::Up)){
			if(index > 0){
				prevIndex = index--;
				menuScrollSound.play();
			}
			else{
				prevIndex = index;
				index = MENUSIZE - 1;
				rectangleSpeed *= (MENUSIZE + 1);
				menuScrollSound.play();
			}
		}

		if(input->keyPressed(sf::Keyboard::Down)){
			if(index < MENUSIZE - 1){
				prevIndex = index++;
				menuScrollSound.play();
			}
			else{
				prevIndex = index;
				index = 0;
				rectangleSpeed *= MENUSIZE;
				menuScrollSound.play();
			}
		}

		if(input->keyPressed(sf::Keyboard::Return)){
			if(index == NEWGAME){
				ScreenManager::getInstance().addScreen(new GroundZeroScr());
				ScreenManager::getInstance().setTransition(true);
			}
			if(index == QUIT){
				rain.stop();
				mgs3startscreen.stop();
				quitgame.play();
				ScreenManager::getInstance().setFadeOut(true);
				ScreenManager::getInstance().setIncrease(true);
				exitProgram = true;
			}
		}
	}
}//end of handleEvent(event)

void MenuScreen::update(sf::RenderWindow &Window){
	if(exitProgram && !ScreenManager::getInstance().inFadeOut() /*&& quitgame.getStatus() != sf::Sound::Playing*/){
		Window.close();
	}

	if(blackRectangle.getPosition().y > menuText[index].getPosition().y){
		blackRectangle.move(sf::Vector2f(0, -1 * rectangleSpeed * ScreenManager::getInstance().timeBetwFrame));
	}

	if(blackRectangle.getPosition().y < menuText[index].getPosition().y){
		blackRectangle.move(sf::Vector2f(0, rectangleSpeed * ScreenManager::getInstance().timeBetwFrame));
	}

	menuText[prevIndex].setColor(sf::Color::Black);
	if(blackRectangle.getGlobalBounds().intersects(menuText[index].getGlobalBounds())){
		menuText[index].setColor(sf::Color::White);
	}

	for(int i = 0; i < DROPNUM; i++){
		rainAnimation[i].update(Window);
	}

}//end of update()*/

void MenuScreen::draw(sf::RenderWindow &Window){
	Window.draw(backGroundSprite);
	Window.draw(blackRectangle);
	for(int i = 0; i < MENUSIZE; i++){
		Window.draw(menuText[i]);
	}

	for(int i = 0; i < DROPNUM; i++){
		rainAnimation[i].draw(Window);
	}
}//end of draw(window)*/

void MenuScreen::display(sf::RenderWindow &Window){
	Window.display();
}//end of display(window)*/

//accessors
float MenuScreen::getRectangleSpeed(){
	return rectangleSpeed;
}

//mutators
void MenuScreen::setRectangleSpeed(float rectangleSpeed){
	this->rectangleSpeed = rectangleSpeed;
}

void MenuScreen::restoreDefaultRectangleSpeed(){
	rectangleSpeed = 200.f;
}
