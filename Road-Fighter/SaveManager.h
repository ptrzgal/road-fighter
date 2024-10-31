#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "../external/json.hpp"

using json = nlohmann::json;

class SaveManager {
    std::string filePath;
    std::string bestPlayerNickname;
    long long highestScore;
    json jsonData;

    void saveToFile();
public:
    SaveManager();
    std::string getBestPlayerNickname();
    long long getHighestScore();
    void updateHighestScore(const std::string& playerNickname, long long score);
};

#endif // !SAVEMANAGER_H
