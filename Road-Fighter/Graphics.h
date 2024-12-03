#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class Graphics {
	std::unordered_map<std::string, sf::Texture> texturesMap;

	void loadTexture(const std::string& filePath);
public:
	Graphics();
	sf::Texture& getTexture(const std::string& textureName);
};

#endif // !GRAPHICS_H