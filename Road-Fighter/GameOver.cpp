#include "GameOver.h"

void GameOver::centerText(sf::Text& text, float height) {
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(sf::Vector2f(400, height));
}

void GameOver::setupText(Fonts& font, sf::Text& text, const std::string& str, float height) {
    text.setFont(font.getFont("scoreboard-font.ttf"));
    text.setString(str);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2);
    centerText(text, height);
}

void GameOver::updateTextColor() {
    tryAgainText.setFillColor(selectedOption == 0 ? sf::Color::Red : sf::Color::White);
    exitGameText.setFillColor(selectedOption == 1 ? sf::Color::Red : sf::Color::White);
}

GameOver::GameOver(Fonts& font) {
    setupText(font, highestScoreText, "Highest Score", 100);
    setupText(font, playerScoreText, "Your Score", 180);
    setupText(font, tryAgainText, "Try Again", 260);
    setupText(font, exitGameText, "Exit Game", 340);
    updateTextColor();
}

void GameOver::draw(sf::RenderWindow& window) {
    window.draw(highestScoreText);
    window.draw(playerScoreText);
    window.draw(tryAgainText);
    window.draw(exitGameText);
}

void GameOver::handleInput(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            selectedOption = (selectedOption - 1 + 2) % 2;
            updateTextColor();
        }
        else if (event.key.code == sf::Keyboard::Down) {
            selectedOption = (selectedOption + 1) % 2;
            updateTextColor();
        }
    }
}

int GameOver::getSelectedOption() {
    return selectedOption;
}

void GameOver::updateHighestScore(const std::string& text) {
    highestScoreText.setString(text);
    centerText(highestScoreText, 100);
}

void GameOver::updatePlayerScore(const std::string& text) {
    playerScoreText.setString(text);
    centerText(playerScoreText, 180);
}