
#include "PositionalObject.hpp"
#include <ncurses.h>
#include <vector>

extern std::vector<PositionalObject*> global_collision_detection;

PositionalObject::PositionalObject(size_t nx, size_t ny)
    : x(nx), y(ny)
{
    global_collision_detection.push_back(this);
}

size_t PositionalObject::GetX() const
{
    return x;
}

size_t PositionalObject::GetY() const
{
    return y;
}

bool PositionalObject::CollidesWith(const PositionalObject& other) const
{
    return (x == other.x && y == other.y);
}

bool PositionalObject::IsOutOfBounds() const
{
    if (x == 0 || y == 0)
        return true;
    
    if (x >= size_t(stdscr->_maxx) || y >= size_t(stdscr->_maxy))
        return true;
    
    return false;
}