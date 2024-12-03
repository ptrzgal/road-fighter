#ifndef ENEMYCARS_H
#define ENEMYCARS_H

#include "Background.h"
#include <vector>
#include <string>
#include <random>
#include <thread>
#include <chrono>
#include <mutex>

class EnemyCars {
	sf::Sprite enemySprite;
	std::vector<std::string> enemyTextureFiles;
	float speedMovingDown;

	void settingTextureNames();
	std::string getRandomTexture();
	void selectRandomTextureAndSpriteSetting(Graphics& graphics);
public:
	EnemyCars(Background& background, Graphics& graphics, float speed = 0.3f);
	const sf::Sprite& getEnemySprite() const;
	void enemyMovingDown();
	void setStartingPosition(Background& background);
};

#endif // !ENEMYCARS_H