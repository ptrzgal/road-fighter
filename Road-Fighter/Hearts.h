#ifndef HEARTS_H
#define HEARTS_H

#include "Graphics.h"

class Hearts {
	std::vector<sf::Sprite> heartSpritesVector;
	unsigned int numberOfLives;
	unsigned int playerLives;
public:
	Hearts(const std::string& textureName, Graphics& graphics, unsigned int numberOfLives, sf::RenderWindow& window);
	void setStartingPosition(sf::RenderWindow& window);
	void reducePlayerLife(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	unsigned int getPlayerLives();
	void reset(Graphics& graphics, sf::RenderWindow& window, std::string textureName);
	void addLife(Graphics& graphics, sf::RenderWindow& window);
};	

#endif // !HEARTS_H
