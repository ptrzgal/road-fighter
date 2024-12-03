#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "Fonts.h"

class ScoreBoard {
	sf::Text scoreText;
	unsigned long long score;

	void scoreBoardVisualSettings();
public:
	ScoreBoard(Fonts& font);
	void setScore(float seconds);
	void update();
	void draw(sf::RenderWindow& window);
	void reset();
	unsigned long long getScore();
};

#endif // !SCOREBOARD_H