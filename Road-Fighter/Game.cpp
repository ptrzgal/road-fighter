#include "Game.h"

Game::Game() : window(sf::VideoMode(840, 650), "Road Fighter", sf::Style::Close),
background("background.png", graphics),
player("player-car.png", window, graphics),
hearts("heart.png", graphics, 3, window),
scoreBoard(font),
mainMenu(font, graphics, window),
gameState(GameState::NicknameInput),
gameOver(font),
nicknameInput(font),
textBox(font, false),
save() { 
    highestScoreSetUp();
}

void Game::gameEvents() {
    while (window.pollEvent(evnt)) {
        switch (gameState) {
        case GameState::NicknameInput:
            switch (evnt.type) {
            case sf::Event::KeyPressed:
                switch (evnt.key.code) {
                case sf::Keyboard::Up:
                case sf::Keyboard::Down:
                    nicknameInput.handleInput(evnt);
                    break;
                case sf::Keyboard::Enter:
                    switch (nicknameInput.getSelectedOption()) {
                    case 0:
                        textBox.setSelected(true);
                        break;
                    case 1:
                        if (!textBox.getText().empty()) {
                            playerNickname = textBox.getText();
                            gameState = GameState::MainMenu;
                        }
                        break;
                    case 2:
                        window.close();
                        break;
                    }
                    break;
                }
                break;
            case sf::Event::TextEntered:
                if (nicknameInput.getSelectedOption() == 0) {
                    textBox.typedOn(evnt);
                }
                break;
            }
            break;
        case GameState::MainMenu:
            switch (evnt.type) {
            case sf::Event::KeyPressed:
                switch (evnt.key.code) {
                case sf::Keyboard::Up:
                case sf::Keyboard::Down:
                    mainMenu.handleInput(evnt, gameState);
                    break;
                case sf::Keyboard::Enter:
                    switch (mainMenu.getSelectedOption()) {
                    case 0:
                        gameState = GameState::Gameplay;
                        break;
                    case 1:
                        save = SaveManager();
                        highestScoreText.setString("Highest Score: " + std::to_string(save.getHighestScore()) + " by " + save.getBestPlayerNickname());
                        highestScoreText.setPosition(420.f - highestScoreText.getLocalBounds().width / 2.f, 325.f);
                        gameState = GameState::HighestScore;
                        break;
                    case 2:
                        gameState = GameState::Tutorial;
                        break;
                    case 3:
                        gameState = GameState::AboutGame;
                        break;
                    case 4:
                        window.close();
                        break;
                    }
                    break;
                }
                break;
            case sf::Event::Closed:
                window.close();
                break;
            }
            break;
        case GameState::Gameplay:
            switch (evnt.type) {
            case sf::Event::KeyPressed:
                switch (evnt.key.code) {
                case sf::Keyboard::Left:
                    player.moveLeft();
                    break;
                case sf::Keyboard::Right:
                    player.moveRight();
                    break;
                }
                break;
            case sf::Event::Closed:
                window.close();
                break;
            }
            break;
        case GameState::HighestScore:
            if (evnt.type == sf::Event::KeyPressed) {
                gameState = GameState::MainMenu;
            }
            break;
        case GameState::AboutGame:
            if (evnt.type == sf::Event::KeyPressed) {
                gameState = GameState::MainMenu;
            }
            break;
        case GameState::Tutorial:
            switch (evnt.type) {
            case sf::Event::KeyPressed:
                mainMenu.updateTutorialSprite(gameState);
                break;
            }
            break;
        case GameState::GameOver:
            switch (evnt.type) {
            case sf::Event::KeyPressed:
                switch (evnt.key.code) {
                case sf::Keyboard::Up:
                case sf::Keyboard::Down:
                    gameOver.handleInput(evnt);
                    break;
                case sf::Keyboard::Enter:
                    switch (gameOver.getSelectedOption()) {
                    case 0:
                        save.updateHighestScore(playerNickname, scoreBoard.getScore());
                        resetGameValues();
                        gameState = GameState::Gameplay;
                        break;
                    case 1:
                        save.updateHighestScore(playerNickname, scoreBoard.getScore());
                        window.close();
                        break;
                    }
                }
                break;
            case sf::Event::Closed:
                window.close();
                break;
            }
            break;
        }
    }
}

void Game::run() {
    while (window.isOpen()) {
        gameEvents(); 
        switch (gameState) {
        case GameState::NicknameInput:
            window.clear();
            nicknameInput.draw(window);
            textBox.draw(window);
            window.display();
            break;
        case GameState::MainMenu:
            window.clear();
            mainMenu.draw(window);
            window.display();
            break;
        case GameState::Gameplay:
            gameClock.restart(); 
            while (window.isOpen() && gameState == GameState::Gameplay) {
                gameEvents();
                collision.checkIfPlayerOnTheRoad(player.getSprite(), background.getLeftBarrier(), background.getRightBarrier());
                enemySpawnByClock();
                enemyInstanceMovingDown();
                lifePlusSpawnByClock();
                lifePlusInstanceMovingDown();
                checkCollisionsInGame();
                background.movingDown();
                renderForGameplay();
                scoreBoard.setScore(gameClock.getElapsedTime().asSeconds());
            }
            break;
        case GameState::HighestScore:
            window.clear();
            window.draw(highestScoreText);
            window.display();
            break;
        case GameState::Tutorial:
            window.clear();
            window.draw(mainMenu.getCurrentTutorialSprite()); 
            window.display();
            break;
        case GameState::AboutGame:
            window.clear();
            window.draw(mainMenu.getAboutGameText());
            window.display();
            break;
        case GameState::GameOver:
            window.clear();
            gameOver.draw(window);
            gameOver.updateHighestScore("Highest Score: " + std::to_string(save.getHighestScore()));
            gameOver.updatePlayerScore("Your Score: " + std::to_string(scoreBoard.getScore()));
            window.display();
            break;
        }
    }
}

void Game::renderForGameplay() {
    window.clear();
    background.draw(window);
    hearts.draw(window);
    player.draw(window);
    for (const auto& enemy : enemyCars) {
        window.draw(enemy.getEnemySprite());
    }
    for (const auto& lifePlus : lifePlusIcons) {
        window.draw(lifePlus.getSprite());
    }
    scoreBoard.draw(window);
    window.display();
}

void Game::enemySpawnByClock() {
    if (enemySpawnClock.getElapsedTime().asSeconds() > 1.f) {
        EnemyCars newEnemy(background, graphics);
        while (isHeartsOrEnemyColliding(newEnemy.getEnemySprite())) {
            newEnemy.setStartingPosition(background);
        }
        enemyCars.push_back(newEnemy);
        enemySpawnClock.restart();
    }
}

void Game::enemyInstanceMovingDown() {
    for (auto& enemy : enemyCars) {
        enemy.enemyMovingDown();
    }
}

void Game::lifePlusSpawnByClock() {
    if (lifePlusSpawnClock.getElapsedTime().asSeconds() > 10.f) {
        LifePlus newLifePlus(graphics, background);
        while (isHeartsOrEnemyColliding(newLifePlus.getSprite())) {
            newLifePlus.setStartingPosition(background);
        }
        lifePlusIcons.push_back(newLifePlus);
        lifePlusSpawnClock.restart();
    }
}

void Game::lifePlusInstanceMovingDown() {
    for (auto& lifePlus : lifePlusIcons) {
        lifePlus.movingDown();
    }
}

bool Game::isHeartsOrEnemyColliding(const sf::Sprite& sprite) {
    for (const auto& enemy : enemyCars) {
        if (sprite.getGlobalBounds().intersects(enemy.getEnemySprite().getGlobalBounds())) {
            return true;
        }
    }
    for (const auto& lifePlus : lifePlusIcons) {
        if (sprite.getGlobalBounds().intersects(lifePlus.getSprite().getGlobalBounds())) {
            return true;
        }
    }
    return false;
}

void Game::checkCollisionsInGame() {
    std::vector<sf::Sprite> enemySprites;
    for (const auto& enemy : enemyCars) {
        enemySprites.push_back(enemy.getEnemySprite());
    }

    if (collision.checkPlayerEnemyCollision(player.getSprite(), enemySprites, hearts, window)) {
        sounds.playSound("crash");
        enemyCars.clear();
    }

    if (collision.checkPlayerLifePlusCollision(player, lifePlusIcons) && hearts.getPlayerLives() < 3) {
        lifePlus.applyPower(hearts, graphics, window);
        lifePlusIcons.erase(
            std::remove_if(
                lifePlusIcons.begin(),
                lifePlusIcons.end(),
                [&](LifePlus& lp) {
                    std::vector<LifePlus> tempVector{ lp };
                    return collision.checkPlayerLifePlusCollision(player, tempVector);
                }
            ),
            lifePlusIcons.end()
        );
    }

    if (hearts.getPlayerLives() <= 0) {
        gameState = GameState::GameOver;
    }
}

void Game::resetGameValues() {
    player.setStartingPosition(window);
    hearts.reset(graphics, window, "heart.png");
    enemyCars.clear();
    gameClock.restart();
    scoreBoard.reset();
}

void Game::highestScoreSetUp() {
    highestScoreText.setFont(font.getFont("scoreboard-font.ttf"));
    highestScoreText.setCharacterSize(50);
    highestScoreText.setFillColor(sf::Color::White);
    highestScoreText.setStyle(sf::Text::Bold);
    highestScoreText.setOutlineColor(sf::Color::Black);
    highestScoreText.setOutlineThickness(2);
}