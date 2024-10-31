#include "LifePlus.h"

std::mt19937 gen2(std::random_device{}());

LifePlus::LifePlus(Graphics& graphics, Background& background) {
	lifePlusSprite.setTexture(graphics.getTexture("heart.png"));
    setStartingPosition(background);
}

LifePlus::LifePlus() {}

void LifePlus::setStartingPosition(Background& background) {
    std::uniform_int_distribution<> dis(0, background.getStreetLanesLocation().size() - 1);
    float middleOfRoadLane = background.getStreetLanesLocation()[dis(gen2)];
    float halfWidthOfCar = middleOfRoadLane - (lifePlusSprite.getLocalBounds().width / 2.0f);
    float settingCarAboveScreen = -lifePlusSprite.getLocalBounds().height;
    lifePlusSprite.setPosition(halfWidthOfCar, settingCarAboveScreen);
}

const sf::Sprite& LifePlus::getSprite() const {
    return lifePlusSprite;
}

void LifePlus::movingDown() {
    lifePlusSprite.move(0, 0.3);
}

void LifePlus::applyPower(Hearts& heart, Graphics& graphics, sf::RenderWindow& window) {
    heart.addLife(graphics, window);
}