#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Fonts.h"
#include <sstream>
#include <regex>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class TextBox {
	sf::Text textBox;
	std::ostringstream text;
	bool isSelected = false;

	void inputLogic(int charTyped);
	void deleteLastChar();
public:
	TextBox(Fonts& font, bool sel);
	void setFont(Fonts& font);
	void setPosition(sf::Vector2f pos);
	void setSelected(bool sel);
	std::string getText();
	sf::Text getTextBox();
	void draw(sf::RenderWindow& window);
	void typedOn(sf::Event& input);
	bool isValidText(const std::string& text);
};

#endif // !NICKNAMEINPUT_H
