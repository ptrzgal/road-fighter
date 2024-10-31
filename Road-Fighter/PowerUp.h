#ifndef POWERUP_H
#define POWERUP_H

#include "Background.h"
#include <random>

class PowerUp {
public:
	virtual const sf::Sprite& getSprite() const = 0;
	virtual void movingDown() = 0;
};

#endif // !POWERUP_H
