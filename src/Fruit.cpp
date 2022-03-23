
#include "Fruit.hpp"
#include "SnakeHead.hpp"
#include <random>

extern std::vector<PositionalObject*> global_collision_detection;

void Fruit::MoveRandomly()
{
    static std::random_device dev;
    static std::mt19937 rng(dev());

    std::uniform_int_distribution<std::mt19937::result_type> randx(1, stdscr->_maxx);
    std::uniform_int_distribution<std::mt19937::result_type> randy(1, stdscr->_maxy);

    x = randx(rng);
    y = randy(rng);

    if (this->IsOutOfBounds())
        this->MoveRandomly();
    
    for (const PositionalObject* obj : global_collision_detection)
    {
        if (obj->CollidesWith(*this))
            this->MoveRandomly();
    }
}

void RenderFruit(std::vector<Fruit> fruits)
{
    for (const auto& fruit : fruits)
    {
        mvaddch(fruit.GetY(), fruit.GetX(), 'O');
    }
}
