#if !defined SNAKE_HPP
#define SNAKE_HPP
#include <list>
#include <prg_interactive.hpp>
#include "positions.hpp"
enum class Direction {
    North = 1, East, South, West
};


class Snake {
public:

    virtual void Update() = 0;

    void move();

    void changeDirection(Direction new_direction);

    const Position& getPosition() const {return position_;}
    void render(prg::Canvas& canvas) const;
    void RemoveTail(int dif);
    void Collision();


    Position position_ {50,50};
    int tailSize = 0;
    int growthRate = 3;
    int minTailSize = 3;

    std::list<Position> tail_;

private:
    Direction direction_ {Direction::North};

};

#endif // SNAKE_HPP
