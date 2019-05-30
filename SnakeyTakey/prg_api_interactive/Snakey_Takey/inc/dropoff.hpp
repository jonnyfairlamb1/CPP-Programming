#if !defined DROPOFF_HPP
#define DROPOFF_HPP
#include "snake.hpp"
#include <prg_interactive.hpp>


class DropOff {
public:

void PlayerScores(Snake& snake_);
void AIScores(Snake& snake_);
void render(prg::Canvas& canvas) const;
void InArea(Snake& snake_);

int playerScore = 0;
int AIScore = 0;
bool scored = false;

int diff = 0;

private:
};
#endif // DROPOFF_HPP
