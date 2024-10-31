#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Graphics.h"

class Background {
	sf::Sprite backgroundSprite1;
	sf::Sprite backgroundSprite2;
	std::vector<float> streetLanesLocation;
	float leftBarrier, rightBarrier;
	float scrollSpeed;
	float windowHeight;

	void setStartingPosition();
public:
	Background(const std::string& textureName, Graphics& graphics);
	float getLeftBarrier();
	float getRightBarrier();
	std::vector<float> getStreetLanesLocation();
	void movingDown();
	void draw(sf::RenderWindow& window);
};

#endif // !BACKGROUND_H