
#ifndef FRUIT_HPP
#define FRUIT_HPP

#include "PositionalObject.hpp"
#include "SnakeHead.hpp"
#include <ncurses.h>
#include <vector>

typedef unsigned long size_t;

class Fruit : public PositionalObject
{
public:
    using PositionalObject::PositionalObject;

    void MoveRandomly();

    friend void RenderFruit(std::vector<Fruit> fruits);
};

#endif /* FRUIT_HPP */