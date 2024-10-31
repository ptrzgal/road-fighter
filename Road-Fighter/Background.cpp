#include "Background.h"

Background::Background(const std::string& textureName, Graphics& graphics) : 
leftBarrier(174), 
rightBarrier(670), 
streetLanesLocation({ 230,355, 488, 618 }), 
scrollSpeed(0.4f) {
	backgroundSprite1.setTexture(graphics.getTexture(textureName));
	backgroundSprite2.setTexture(graphics.getTexture(textureName));
	setStartingPosition();
}

float Background::getLeftBarrier() {
	return leftBarrier;
}

float Background::getRightBarrier() {
	return rightBarrier;
}

std::vector<float> Background::getStreetLanesLocation() {
	return streetLanesLocation;
}

void Background::movingDown() {
	backgroundSprite1.move(0, scrollSpeed);
	backgroundSprite2.move(0, scrollSpeed);
	if (backgroundSprite1.getPosition().y >= windowHeight) {
		backgroundSprite1.setPosition(0, backgroundSprite2.getPosition().y - windowHeight);
	}
	if (backgroundSprite2.getPosition().y >= windowHeight) {
		backgroundSprite2.setPosition(0, backgroundSprite1.getPosition().y - windowHeight);
	}
}

void Background::draw(sf::RenderWindow& window) {
	window.draw(backgroundSprite1);
    window.draw(backgroundSprite2);
}

void Background::setStartingPosition() {
	windowHeight = backgroundSprite1.getTexture()->getSize().y;
	backgroundSprite1.setPosition(0, 0);
	backgroundSprite2.setPosition(0, -windowHeight);
}