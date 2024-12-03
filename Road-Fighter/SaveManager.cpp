#include "SaveManager.h"

SaveManager::SaveManager() {
    filePath = "../data/highest-score.json";
    if (!std::filesystem::exists(filePath)) {
        std::cerr << "The file does not exist!" << std::endl;
        return;
    }
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        std::cerr << "The file cannot be opened!" << std::endl;
        return;
    }
    inputFile >> jsonData;
    inputFile.close();
    try {
        bestPlayerNickname = jsonData.at("player_nickname").get<std::string>();
        highestScore = jsonData.at("highest_score").get<long long>();
    }
    catch (json::exception& e) {
        std::cerr << "Data access error: " << e.what() << std::endl;
    }
}

std::string SaveManager::getBestPlayerNickname() {
    return bestPlayerNickname;
}

long long SaveManager::getHighestScore() {
    return highestScore;
}

void SaveManager::saveToFile() {
    std::ofstream outputFile(filePath);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return;
    }
    outputFile << std::setw(4) << jsonData << std::endl;
    outputFile.close();
}

void SaveManager::updateHighestScore(const std::string& playerNickname, long long score) {
    if (score > highestScore) {
        bestPlayerNickname = playerNickname;
        highestScore = score;
        jsonData["player_nickname"] = playerNickname;
        jsonData["highest_score"] = score;
        saveToFile();
    }
}
