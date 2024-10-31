#include "CheckCollision.h"

void CheckCollision::checkIfPlayerOnTheRoad(sf::Sprite& playerSprite, float leftBound, float rightBound) {
    sf::Vector2f position = playerSprite.getPosition();
    if (position.x < leftBound) {
        playerSprite.setPosition(leftBound, position.y);
    }
    else if (position.x + playerSprite.getLocalBounds().width > rightBound) {
        playerSprite.setPosition(rightBound - playerSprite.getLocalBounds().width, position.y);
    }
}

bool CheckCollision::checkPlayerEnemyCollision(sf::Sprite& playerSprite, std::vector<sf::Sprite>& enemySprites, Hearts& hearts, sf::RenderWindow& window) { 
    sf::FloatRect playerBounds = playerSprite.getGlobalBounds();
    auto collision = std::ranges::find_if(enemySprites, [&](const sf::Sprite& enemySprite) { return playerBounds.intersects(enemySprite.getGlobalBounds()); });
    if (collision != std::ranges::end(enemySprites)) {
        hearts.reducePlayerLife(window);
        return true;
    }
    return false;
}

bool CheckCollision::checkPlayerLifePlusCollision(Player& player, std::vector<LifePlus>& lifePlusIcons) {
    sf::FloatRect playerBounds = player.getSprite().getGlobalBounds();
    for (auto& lifePlus : lifePlusIcons) {
        sf::FloatRect lifePlusBounds = lifePlus.getSprite().getGlobalBounds();
        if (playerBounds.intersects(lifePlusBounds)) {
            return true;
        }
    }
    return false;
}
