#if !defined AISNAKE_HPP
#define AISNAKE_HPP
#include <list>
#include <prg_interactive.hpp>

class collectables;

class AISnake : public Snake {

public:
    void moveAI(int step, Direction dir);
    void Update() override;
    void RandomTail();
    AISnake(collectables& col): fruit_(col){}



private:
    collectables& fruit_;
    Position closestFruit{0,0};

    bool hasTarget = false;
    int stepx = 0;
    int stepy = 0;
    int AIPosX = 750;
    int AIPosY = 50;
    int randomTail = 8;
};

#endif // SNAKE_HPP
