#include "NicknameInput.h"

void NicknameInput::centerText(sf::Text& text, float height) {
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(sf::Vector2f(400, height));
}

void NicknameInput::setUpText(sf::Text& text, Fonts& font, std::string str, int height, int size) {
    text.setFont(font.getFont("scoreboard-font.ttf"));
    text.setString(str);
    text.setCharacterSize(size);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2);
    centerText(text, height);
}

void NicknameInput::setUpPromptText(sf::Text& text, Fonts& font, std::string str, int height) {
    text.setFont(font.getFont("scoreboard-font.ttf"));
    text.setString(str);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2);
    text.setPosition(sf::Vector2f(100, height));
}

NicknameInput::NicknameInput(Fonts& font) {
    setUpText(titleText ,font, "Road Fighter", 100, 50);
    setUpText(nextButtonText, font, "Next", 340, 50);
    setUpText(exitText, font, "Exit", 420, 50);
    setUpPromptText(promtText, font, "Your Nickname: ", 180);
    setUpText(requirementsText, font, "- max. 8 letters\n- no special characters", 273, 37);
    updateTextColor();
}

void NicknameInput::draw(sf::RenderWindow& window) {
    window.draw(titleText);
    window.draw(promtText);
    window.draw(requirementsText);
    window.draw(nextButtonText);
    window.draw(exitText);
}

void NicknameInput::handleInput(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            selectedOption = (selectedOption - 1 + 3) % 3;
            updateTextColor();
        }
        else if (event.key.code == sf::Keyboard::Down) {
            selectedOption = (selectedOption + 1) % 3;
            updateTextColor();
        }
    }
}

void NicknameInput::updateTextColor() {
    promtText.setFillColor(selectedOption == 0 ? sf::Color::Red : sf::Color::White);
    nextButtonText.setFillColor(selectedOption == 1 ? sf::Color::Red : sf::Color::White);
    exitText.setFillColor(selectedOption == 2 ? sf::Color::Red : sf::Color::White);
}

int NicknameInput::getSelectedOption() {
    return selectedOption;
}