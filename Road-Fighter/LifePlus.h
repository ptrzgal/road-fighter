#ifndef LIFEPLUS_H
#define LIFEPLUS_H

#include "PowerUp.h"
#include "Hearts.h"

class LifePlus : public PowerUp {
	sf::Sprite lifePlusSprite;
public:
	LifePlus(Graphics& graphics, Background& background);
	LifePlus();
	void setStartingPosition(Background& background);
	const sf::Sprite& getSprite() const override;
	void movingDown() override;
	void applyPower(Hearts& heart, Graphics& graphics, sf::RenderWindow& window);
};

#endif // !LIFEPLUS_H
