#ifndef MAINMENU_H
#define MAINMENU_H

#include "Fonts.h"
#include "SaveManager.h"

import GameStateModule;

class MainMenu {
    sf::Text startGameText;
    sf::Text highestScoreText;
    sf::Text tutorialText;
    sf::Text aboutText;
    sf::Text exitGameText;
    sf::Text highestScoreByPlayerText;
    sf::Text aboutGameText;
    sf::Sprite tutorialPlayerSprite;
    sf::Sprite tutorialEnemySprite;
    sf::Sprite tutorialHeartSprite;
    sf::Sprite tutorialScoreSprite;
    std::vector<sf::Sprite> tutorialSprites;
    int currentTutorialSpriteIndex;
    int selectedOption;

    void setupText(Fonts& font, sf::Text& text, const std::string& str, float height);
    void updateTextColor();
    void centerText(sf::Text& text, float height);
public:
    MainMenu(Fonts& fonts, Graphics& graphics, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    void handleInput(sf::Event event, GameState& gameState);
    int getSelectedOption() const;
    sf::Text& getAboutGameText();
    void updateTutorialSprite(GameState& gameState);
    sf::Sprite& getCurrentTutorialSprite();
    void centerSprite(sf::Sprite& sprite, sf::RenderWindow& window);
};

#endif // MAINMENU_H
