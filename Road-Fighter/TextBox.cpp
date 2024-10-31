#include "TextBox.h"
#include <regex>

bool TextBox::isValidText(const std::string& text) {
    std::regex regexPattern("^[A-Za-z0-9]{1,8}$");
    return std::regex_match(text, regexPattern);
}

void TextBox::inputLogic(int charTyped) {
    if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
        std::string currentText = text.str() + static_cast<char>(charTyped);
        if (isValidText(currentText)) {
            text << static_cast<char>(charTyped);
        }
    }
    else if (charTyped == DELETE_KEY) {
        if (text.str().length() > 0) {
            deleteLastChar();
        }
    }
    textBox.setString(text.str() + "_");
}

void TextBox::deleteLastChar() {
    std::string t = text.str();
    std::string newT = "";
    for (int i = 0; i < t.length() - 1; i++) {
        newT += t[i];
    }
    text.str("");
    text << newT;
    textBox.setString(text.str() + "_");
}

TextBox::TextBox(Fonts& font, bool sel) {
    textBox.setFont(font.getFont("scoreboard-font.ttf"));
    textBox.setPosition({ 340, 180 });
    textBox.setCharacterSize(50);
    textBox.setFillColor(sf::Color::White);
    isSelected = sel;
    if (sel) {
        textBox.setString("_");
    }
    else {
        textBox.setString("");
    }
}

void TextBox::setFont(Fonts& font) {
    textBox.setFont(font.getFont("scoreboard-font.ttf"));
}

void TextBox::setPosition(sf::Vector2f pos) {
    textBox.setPosition(pos);
}

void TextBox::setSelected(bool sel) {
    isSelected = sel;
    if (!sel) {
        std::string t = text.str();
        std::string newT = "";
        for (int i = 0; i < t.length(); i++) {
            newT += t[i];
        }
        textBox.setString(newT);
    }
}

std::string TextBox::getText() {
    return text.str();
}

sf::Text TextBox::getTextBox() {
    return textBox;
}

void TextBox::draw(sf::RenderWindow& window) {
    window.draw(textBox);
}

void TextBox::typedOn(sf::Event& input) {
    if (isSelected) {
        int charTyped = input.text.unicode;
        if (charTyped < 128) {
            inputLogic(charTyped);
        }
    }
}
