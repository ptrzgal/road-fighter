#include "Player.h"

Player::Player(const std::string& textureName, sf::RenderWindow& window, Graphics& graphics) : movementSpeed(10.f) {
	playerSprite.setTexture(graphics.getTexture(textureName));
	setStartingPosition(window);
}

sf::Sprite& Player::getSprite() {
	return playerSprite;
}

void Player::moveLeft() {
	playerSprite.move(-movementSpeed, 0.f);
}

void Player::moveRight() {
	playerSprite.move(movementSpeed, 0.f);
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(playerSprite);
}

void Player::setStartingPosition(sf::RenderWindow& window) {
	playerSprite.setPosition(window.getSize().x / 2 - playerSprite.getLocalBounds().width / 2,
		window.getSize().y - playerSprite.getLocalBounds().height);
}