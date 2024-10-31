#include "ScoreBoard.h"

void ScoreBoard::scoreBoardVisualSettings() {
    scoreText.setStyle(sf::Text::Bold);
    scoreText.setOutlineColor(sf::Color::Black);
    scoreText.setOutlineThickness(2);
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color::Yellow);
    scoreText.setPosition(10, 10);
}

ScoreBoard::ScoreBoard(Fonts& font) : score(0) {
    scoreText.setFont(font.getFont("scoreboard-font.ttf"));
    scoreBoardVisualSettings();
    update();
}

void ScoreBoard::setScore(float seconds) {
    score = static_cast<unsigned int>(seconds);
    update();
}

void ScoreBoard::update() {
    scoreText.setString("Score: " + std::to_string(score));
}

void ScoreBoard::draw(sf::RenderWindow& window) {
    window.draw(scoreText);
}

void ScoreBoard::reset() {
    score = 0;
}

unsigned long long ScoreBoard::getScore() {
    return score;
}