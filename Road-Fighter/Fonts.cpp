#include "Fonts.h"

Fonts::Fonts() {
    loadFonts("../fonts/scoreboard-font.ttf");
}

void Fonts::loadFonts(const std::string& filePath) {
    sf::Font font;
    if (!font.loadFromFile(filePath)) {}
    std::string fileName = filePath.substr(filePath.find_last_of('/') + 1);
    fontsMap[fileName] = font;
}

sf::Font& Fonts::getFont(const std::string& textureName) {
    return fontsMap[textureName];
}