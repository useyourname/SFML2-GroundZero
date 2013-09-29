#include "../Headers/Animation.hpp"

Animation::Animation(){
	active = false;
}//end Animation()

Animation::~Animation(){

}//end of ~Animation()

void Animation::activate(){
	active = true;
}//end of activate()*/

void Animation::deactivate(){
	active = false;
}//end of deactivate()*/

bool Animation::isActive(){
	return this->active;
}//end of isActive()*/

void Animation::loadContent(std::string textBeforeConversion, sf::Texture texture, sf::Vector2f position){
	this->position = position;
	this->textBeforeConversion = textBeforeConversion;
	this->texture = texture;
	this->sprite.setTexture(texture);
	this->text.setString(textBeforeConversion);
	textColor = sf::Color(114, 77, 255);
}//end of loadContent()

void Animation::unloadContent(){

}//end of unloadContent()

void Animation::update(sf::RenderWindow &Window, GameScreen *currentScreen, GameScreen *newScreen){

}//end of update()

void Animation::draw(sf::RenderWindow &Window){
	if(text.getString() != "") Window.draw(text);
	if(sprite.getTexture()) Window.draw(sprite);
}//end of draw(Window)
