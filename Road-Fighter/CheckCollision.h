#ifndef CHECKCOLLISION_H
#define CHECKCOLLISION_H

#include "Player.h"
#include "LifePlus.h"
#include <ranges>

class CheckCollision {
public:
	void checkIfPlayerOnTheRoad(sf::Sprite& playerSprite, float leftBound, float rightBound);
	bool checkPlayerEnemyCollision(sf::Sprite& playerSprite, std::vector<sf::Sprite>& enemySprites, Hearts& hearts, sf::RenderWindow& window);
	bool checkPlayerLifePlusCollision(Player& player, std::vector<LifePlus>& lifePlusIcons);
};

#endif // !CHECKCOLLISION_H