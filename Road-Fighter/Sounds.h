#ifndef SOUNDS_H
#define SOUNDS_H

#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>

class Sounds {
    std::unordered_map<std::string, sf::SoundBuffer> soundsBufferMap;
    std::unordered_map<std::string, sf::Sound> soundsMap;

    void loadSounds(const std::string& filePath, const std::string& soundName);
public:
	Sounds();
    void playSound(const std::string& soundName);
};

#endif // !SOUNDS_H
