#include "EnemyCars.h"

std::mt19937 gen(std::random_device{}());

void EnemyCars::settingTextureNames() {
    enemyTextureFiles = { "enemy-green-car.png", "enemy-amb-car.png", "enemy-blue-car.png", "enemy-limo.png", "enemy-moro-car.png", "enemy-truck.png" };
}

std::string EnemyCars::getRandomTexture() {
    std::uniform_int_distribution<> dis(0, enemyTextureFiles.size() - 1);
    return enemyTextureFiles[dis(gen)];
}

void EnemyCars::selectRandomTextureAndSpriteSetting(Graphics& graphics) {
    std::string randomTexture = getRandomTexture();
    enemySprite.setTexture(graphics.getTexture(randomTexture));
}

void EnemyCars::setStartingPosition(Background& background) {
    std::uniform_int_distribution<> dis(0, background.getStreetLanesLocation().size() - 1);
    float middleOfRoadLane = background.getStreetLanesLocation()[dis(gen)];
    float halfWidthOfCar = middleOfRoadLane - (enemySprite.getLocalBounds().width / 2.0f);
    float settingCarAboveScreen = -enemySprite.getLocalBounds().height;
    enemySprite.setPosition(halfWidthOfCar, settingCarAboveScreen);
}

EnemyCars::EnemyCars(Background& background, Graphics& graphics, float speed) : speedMovingDown(speed) {
    settingTextureNames();
    selectRandomTextureAndSpriteSetting(graphics);
    setStartingPosition(background);
}

const sf::Sprite& EnemyCars::getEnemySprite() const {
    return enemySprite;
}

void EnemyCars::enemyMovingDown() {
    enemySprite.move(0, speedMovingDown);
}
