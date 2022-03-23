
#ifndef SNAKETAILSEGMENT_HPP
#define SNAKETAILSEGMENT_HPP

#include "PositionalObject.hpp"
#include <ncurses.h>

typedef unsigned long size_t;

class SnakeTailSegment : public PositionalObject
{
public:
    using PositionalObject::PositionalObject;

    void SetPosition(size_t nx, size_t ny);

    friend void RenderSnakeTailSegment(const SnakeTailSegment& sts);
};

#endif /* SNAKETAILSEGMENT_HPP */
