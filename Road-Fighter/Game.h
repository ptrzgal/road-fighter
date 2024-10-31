#ifndef GAME_H
#define GAME_H

#include "Sounds.h"
#include "CheckCollision.h"
#include "EnemyCars.h"
#include "ScoreBoard.h"
#include "MainMenu.h"
#include "GameOver.h"
#include "SaveManager.h"
#include "NicknameInput.h"
#include "LifePlus.h"

import GameStateModule;

class Game {
	Graphics graphics;
	Sounds sounds;
	Fonts font;
	sf::RenderWindow window;
	sf::Event evnt;
	Background background;
	Player player;
	CheckCollision collision;
	Hearts hearts;
	ScoreBoard scoreBoard;
	sf::Clock gameClock;
	MainMenu mainMenu;
	GameState gameState;
	GameOver gameOver;
	SaveManager save;
	sf::Text highestScoreText;
	NicknameInput nicknameInput;
	TextBox textBox;
	std::vector<EnemyCars> enemyCars;
	sf::Clock enemySpawnClock;
	std::vector<LifePlus> lifePlusIcons;
	LifePlus lifePlus;
	sf::Clock lifePlusSpawnClock;
	std::string playerNickname;

	void gameEvents();
	void renderForGameplay();
	void enemySpawnByClock();
	void enemyInstanceMovingDown();
	void lifePlusSpawnByClock();
	void lifePlusInstanceMovingDown();
	bool isHeartsOrEnemyColliding(const sf::Sprite& sprite);
	void checkCollisionsInGame();
	void resetGameValues();
	void highestScoreSetUp();
public:
	Game();
	void run();
};

#endif // !GAME_H
