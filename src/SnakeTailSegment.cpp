
#include "SnakeTailSegment.hpp"

void SnakeTailSegment::SetPosition(size_t nx, size_t ny)
{
    x = nx;
    y = ny;
}

void RenderSnakeTailSegment(const SnakeTailSegment& sts)
{
    mvaddch(sts.y, sts.x, '#');
}
