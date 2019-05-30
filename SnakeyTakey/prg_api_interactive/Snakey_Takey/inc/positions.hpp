#if !defined POSITIONS_HPP
#define POSITIONS_HPP

struct Position final{
    int x{0}, y{0};
    Position (int ix, int iy) : x{ix}, y{iy} {}
};

#endif
