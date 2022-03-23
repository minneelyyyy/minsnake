
#ifndef POSITIONALOBJECT_HPP
#define POSITIONALOBJECT_HPP

#include <algorithm>

typedef unsigned long size_t;

/* This class contains no code to change x and y once set. that is up to parent classes to implement */
class PositionalObject
{
protected:
    size_t x, y;

public:
    PositionalObject(size_t nx, size_t ny);

    size_t GetX() const;
    size_t GetY() const;

    bool CollidesWith(const PositionalObject& other) const;
    bool IsOutOfBounds() const;
};

#endif /* POSITIONALOBJECT_HPP */