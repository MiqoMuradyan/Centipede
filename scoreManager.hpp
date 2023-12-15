#ifndef SCORE_MANAGER_HPP
#define SCORE_MANAGER_HPP

#include <iostream>
#include <fstream>

class ScoreManager {
public:
    ScoreManager();
    ~ScoreManager();

    void loadScoreFromFile();
    void saveScoreInFile();

    int getHighScore();

    int getScore();
    void increaseScore(int score);

    int getSpeed();
    void increaseSpeed();
private:
    static int highScore;
    int score;
    int speed;

    void updateHighScore();
};

#endif //SCORE_MANAGER_HPP