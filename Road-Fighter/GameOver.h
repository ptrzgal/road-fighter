#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "Fonts.h"

class GameOver {
	sf::Text highestScoreText;
	sf::Text playerScoreText;
	sf::Text tryAgainText;
	sf::Text exitGameText;
	int selectedOption;

	void centerText(sf::Text& text, float height);
	void setupText(Fonts& font, sf::Text& text, const std::string& str, float height);
	void updateTextColor();
public:
	GameOver(Fonts& font);
	void draw(sf::RenderWindow& window);
	void handleInput(sf::Event event);
	int getSelectedOption();
	void updateHighestScore(const std::string& text);
	void updatePlayerScore(const std::string& text);
};

#endif // !GAMEOVER_H
