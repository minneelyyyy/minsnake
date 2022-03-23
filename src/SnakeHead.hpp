
#ifndef SNAKEHEAD_HPP
#define SNAKEHEAD_HPP

#include "SnakeTailSegment.hpp"
#include "PositionalObject.hpp"
#include <vector>

typedef unsigned long size_t;

enum Direction { NONE, UP, DOWN, LEFT, RIGHT };

class SnakeHead : public PositionalObject
{
private:
    Direction dir = Direction::NONE;
    std::vector<SnakeTailSegment> tail {};

public:
    using PositionalObject::PositionalObject;

    void MoveSnakeInCurrentDirection();
    void ChangeDirection(Direction ndir);

    void AddTailSegment();

    size_t GetTailLength() const;

    bool TailHit() const;

    bool CollidesWithSnake(const PositionalObject& other) const;

    friend void RenderSnake(const SnakeHead& sh);
};

#endif /* SNAKEHEAD_HPP */
