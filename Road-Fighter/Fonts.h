#ifndef FONTS_H
#define FONTS_H

#include "Graphics.h"

class Fonts {
	std::unordered_map<std::string, sf::Font> fontsMap;

	void loadFonts(const std::string& filePath);
public:
	Fonts();
	sf::Font& getFont(const std::string& textureName);
};

#endif // !FONTS_H
