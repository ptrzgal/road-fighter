#include "Hearts.h"

Hearts::Hearts(const std::string& textureName, Graphics& graphics, unsigned int numberOfLives, sf::RenderWindow& window) : numberOfLives(numberOfLives), playerLives(3) {
    for (unsigned int i = 0; i < numberOfLives; ++i) {
        sf::Sprite heartSprite;
        heartSprite.setTexture(graphics.getTexture(textureName));
        heartSpritesVector.push_back(heartSprite);
    }
    setStartingPosition(window);
}

void Hearts::setStartingPosition(sf::RenderWindow& window) {
    float spaceBetweenHearts = 50.f;
    float totalWidth = heartSpritesVector.size() * spaceBetweenHearts; 
    float startX = window.getSize().x - totalWidth - 10.f; 
    float startY = 10.f;
    for (int i = 0; i < heartSpritesVector.size(); ++i) {
        heartSpritesVector[i].setPosition(startX + i * spaceBetweenHearts, startY);
    }
}

void Hearts::reducePlayerLife(sf::RenderWindow& window) {
    if (playerLives > 0) {
        playerLives--;
        if (!heartSpritesVector.empty()) {
            heartSpritesVector.erase(heartSpritesVector.begin());
        }
    }
}

void Hearts::draw(sf::RenderWindow& window) {
    for (const auto& heart : heartSpritesVector) {
        window.draw(heart);
    }
}

unsigned int Hearts::getPlayerLives() {
    return playerLives;
}

void Hearts::reset(Graphics& graphics, sf::RenderWindow& window, std::string textureName) {
    playerLives = numberOfLives;
    heartSpritesVector.clear();
    for (unsigned int i = 0; i < numberOfLives; ++i) {
        sf::Sprite heartSprite;
        heartSprite.setTexture(graphics.getTexture(textureName));
        heartSpritesVector.push_back(heartSprite);
    }
    setStartingPosition(window);
}

void Hearts::addLife(Graphics& graphics, sf::RenderWindow& window) {
    playerLives++;
    sf::Sprite heartSprite;
    heartSprite.setTexture(graphics.getTexture("heart.png"));
    heartSpritesVector.push_back(heartSprite);
    setStartingPosition(window);
}