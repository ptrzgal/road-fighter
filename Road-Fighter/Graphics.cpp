#include "Graphics.h"

Graphics::Graphics() {
	loadTexture("../graphics/background.png");
	loadTexture("../graphics/player-car.png");
	loadTexture("../graphics/enemy-green-car.png");
	loadTexture("../graphics/enemy-amb-car.png");
	loadTexture("../graphics/enemy-blue-car.png");
	loadTexture("../graphics/enemy-limo.png");
	loadTexture("../graphics/enemy-moro-car.png");
	loadTexture("../graphics/enemy-truck.png");
	loadTexture("../graphics/heart.png");
	loadTexture("../graphics/tutorial-gracz.jpg");
	loadTexture("../graphics/tutorial-przeciwnik.jpg");
	loadTexture("../graphics/tutorial-serce.jpg");
	loadTexture("../graphics/tutorial-wynik.jpg");
}

void Graphics::loadTexture(const std::string& filePath) {
	sf::Texture texture;
	if (!texture.loadFromFile(filePath)) {}
	std::string fileName = filePath.substr(filePath.find_last_of('/') + 1);
	texturesMap[fileName] = texture;
}

sf::Texture& Graphics::getTexture(const std::string& textureName) {
	return texturesMap[textureName];
}