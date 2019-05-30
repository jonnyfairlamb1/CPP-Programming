#ifndef COLLECTABLES_HPP
#define COLLECTABLES_HPP
#include <prg_interactive.hpp>
#include <list>
#include "snake.hpp"
#include "positions.hpp"


class collectables
{

    public:
    Position getClosest(const Position& Snake);

    void Collectables();
    void render(prg::Canvas& canvas) const;
    void FruitCollision(Snake& snake_);

    void AddFruit();
    void ListFruit();

    int XCord;
    int YCord;
    std::list<Position> fruit_;

    const Position& getFruitPosition() const {return fruitPosition_;}

    private:
    Position fruitPosition_ {200,200};

};

#endif // COLLECTABLES_H
