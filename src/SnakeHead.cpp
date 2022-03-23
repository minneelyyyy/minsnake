
#include "SnakeHead.hpp"

void SnakeHead::ChangeDirection(Direction ndir)
{
    switch (ndir)
    {
        case Direction::UP:
            if (dir == Direction::DOWN)
                return;
            
            dir = ndir;
            return;

        case Direction::DOWN:
            if (dir == Direction::UP)
                return;
            
            dir = ndir;
            return;

        case Direction::LEFT:
            if (dir == Direction::RIGHT)
                return;
            
            dir = ndir;
            return;

        case Direction::RIGHT:
            if (dir == Direction::LEFT)
                return;
            
            dir = ndir;
        
        case Direction::NONE:
            return;
    }
}

void SnakeHead::MoveSnakeInCurrentDirection()
{
    size_t sx, sy;

    sx = x;
    sy = y;

    for (auto& ts : tail)
    {
        size_t fx = ts.GetX();
        size_t fy = ts.GetY();
        ts.SetPosition(sx, sy);

        sx = fx;
        sy = fy;
    }

    switch (dir)
    {
        case Direction::NONE:
            return;
        
        case Direction::UP:
            y--;
            return;
        
        case Direction::DOWN:
            y++;
            return;
        
        case Direction::LEFT:
            x--;
            return;

        case Direction::RIGHT:
            x++;
            return;
    }
}

void SnakeHead::AddTailSegment()
{
    tail.emplace_back(x, y);
}

size_t SnakeHead::GetTailLength() const
{
    return tail.size();
}

bool SnakeHead::TailHit() const
{
    for (const auto& ts : tail)
    {
        if (this->CollidesWith(ts))
            return true;
    }

    return false;
}

bool SnakeHead::CollidesWithSnake(const PositionalObject& other) const
{
    if (other.GetX() == x && other.GetY() == y)
        return true;

    for (const auto& ts : tail)
    {
        if (other.GetX() == ts.GetX() && other.GetY() == ts.GetY())
            return true;
    }

    return false;
}

void RenderSnake(const SnakeHead& sh)
{
    mvaddch(sh.y, sh.x, '@');

    for (const auto& segment : sh.tail)
    {
        RenderSnakeTailSegment(segment);
    }
}
