#ifndef PLAYER_H
#define PLAYER_H

#include "Graphics.h"

class Player {
	sf::Sprite playerSprite;
	float movementSpeed;
public:
	Player(const std::string& textureName, sf::RenderWindow& window, Graphics& graphics);
	sf::Sprite& getSprite();
	void moveLeft();
	void moveRight();
	void draw(sf::RenderWindow& window);
	void setStartingPosition(sf::RenderWindow& window);
};

#endif // !PLAYER_H