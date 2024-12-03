#include "Sounds.h"

Sounds::Sounds() {
    loadSounds("../sounds/crash.wav", "crash");
}

void Sounds::loadSounds(const std::string& filePath, const std::string& soundName) {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(filePath)) {}
    soundsBufferMap[soundName] = buffer;
    soundsMap[soundName].setBuffer(soundsBufferMap[soundName]);
}

void Sounds::playSound(const std::string& soundName) {
    if (soundsMap.find(soundName) != soundsMap.end()) {
        soundsMap[soundName].play();
    }
}