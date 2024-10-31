#include "MainMenu.h"

void MainMenu::centerText(sf::Text& text, float height) {
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(sf::Vector2f(400, height)); 
}

void MainMenu::setupText(Fonts& font, sf::Text& text, const std::string& str, float height) {
    text.setFont(font.getFont("scoreboard-font.ttf"));
    text.setString(str);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2);
    centerText(text, height);
}

MainMenu::MainMenu(Fonts& font, Graphics& graphics, sf::RenderWindow& window) : selectedOption(0) {
    setupText(font, startGameText, "Start Game", 100);
    setupText(font, highestScoreText, "Highest Score", 180);
    setupText(font, tutorialText, "Tutorial", 260);
    setupText(font, aboutText, "About", 340);
    setupText(font, aboutGameText, "Title: Road Fighter\nAuthor: ptrzgal", 340);
    setupText(font, exitGameText, "Exit Game", 420);
    tutorialPlayerSprite.setTexture(graphics.getTexture("tutorial-gracz.jpg"));
    tutorialEnemySprite.setTexture(graphics.getTexture("tutorial-przeciwnik.jpg"));
    tutorialHeartSprite.setTexture(graphics.getTexture("tutorial-serce.jpg"));
    tutorialScoreSprite.setTexture(graphics.getTexture("tutorial-wynik.jpg"));
    tutorialSprites.push_back(tutorialPlayerSprite);
    tutorialSprites.push_back(tutorialEnemySprite);
    tutorialSprites.push_back(tutorialHeartSprite);
    tutorialSprites.push_back(tutorialScoreSprite);
    for (auto& sprite : tutorialSprites) {
        centerSprite(sprite, window);
    }
    updateTextColor();
}

void MainMenu::draw(sf::RenderWindow& window) {
    window.draw(startGameText);
    window.draw(highestScoreText);
    window.draw(tutorialText);
    window.draw(aboutText);
    window.draw(exitGameText);
}

void MainMenu::handleInput(sf::Event event, GameState& gameState) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            selectedOption = (selectedOption - 1 + 5) % 5;
            updateTextColor();
        }
        else if (event.key.code == sf::Keyboard::Down) {
            selectedOption = (selectedOption + 1) % 5;
            updateTextColor();
        }
        else if (event.key.code == sf::Keyboard::Enter && selectedOption == 3) {
            updateTutorialSprite(gameState);
        }
    }
}

void MainMenu::updateTextColor() {
    startGameText.setFillColor(selectedOption == 0 ? sf::Color::Red : sf::Color::White);
    highestScoreText.setFillColor(selectedOption == 1 ? sf::Color::Red : sf::Color::White);
    tutorialText.setFillColor(selectedOption == 2 ? sf::Color::Red : sf::Color::White);
    aboutText.setFillColor(selectedOption == 3 ? sf::Color::Red : sf::Color::White);
    exitGameText.setFillColor(selectedOption == 4 ? sf::Color::Red : sf::Color::White);
}

int MainMenu::getSelectedOption() const {
    return selectedOption;
}

sf::Text& MainMenu::getAboutGameText() {
    return aboutGameText;
}

void MainMenu::updateTutorialSprite(GameState& gameState) {
    currentTutorialSpriteIndex = (currentTutorialSpriteIndex + 1) % tutorialSprites.size();
    if (currentTutorialSpriteIndex == 0) {
        gameState = GameState::MainMenu;
    }
}

sf::Sprite& MainMenu::getCurrentTutorialSprite() {
    return tutorialSprites[currentTutorialSpriteIndex];
}

void MainMenu::centerSprite(sf::Sprite& sprite, sf::RenderWindow& window) {
    sf::FloatRect spriteRect = sprite.getLocalBounds();
    sprite.setOrigin(spriteRect.left + spriteRect.width / 2.0f, spriteRect.top + spriteRect.height / 2.0f);
    sprite.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f));
}
