#ifndef NICKNAMEINPUT_H
#define NICKNAMEINPUT_H

#include "TextBox.h"

class NicknameInput {
	sf::Text titleText;
	sf::Text promtText;
	sf::Text nextButtonText;
	sf::Text exitText;
	sf::Text requirementsText;
	int selectedOption;

	void centerText(sf::Text& text, float height);
	void setUpText(sf::Text& text, Fonts& font, std::string str, int height, int size);
	void setUpPromptText(sf::Text& text, Fonts& font, std::string str, int height);
	void updateTextColor();
public:
	NicknameInput(Fonts& font);
	void draw(sf::RenderWindow& window);
	void handleInput(sf::Event event);
	int getSelectedOption();
};

#endif // !NICKNAMEINPUT_H
