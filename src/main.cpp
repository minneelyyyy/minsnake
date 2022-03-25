#include <iostream>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>
#include <chrono>
#include <thread>

#include "SnakeHead.hpp"
#include "SnakeTailSegment.hpp"
#include "Fruit.hpp"

std::vector<Direction> inputs;
std::vector<PositionalObject*> global_collision_detection;

void RenderScore(unsigned long score);
void get_user_inputs();

int main()
{
    initscr();
    noecho();
    curs_set(0);

    srand(time(NULL));

    unsigned long score = 0;

    // place player in the middle of the screen
    SnakeHead player(stdscr->_maxx / 2, stdscr->_maxy / 2);

    // create fruits and randomly move them
    std::vector<Fruit> fruits(2, Fruit(0, 0));

    for (auto& fruit : fruits)
    {
        fruit.MoveRandomly();
    }

    // user input listen threrad
    std::thread user_inputs(get_user_inputs);

    for (;;)
    {
        auto start = std::chrono::high_resolution_clock::now();

        // input logic
        if (inputs.size() > 0)
        {
            player.ChangeDirection(inputs[0]);
            inputs.erase(inputs.begin());
        }

        // collision detection
        for (auto& fruit : fruits)
        {
            if (player.CollidesWith(fruit))
            {
                fruit.MoveRandomly();
                player.AddTailSegment();
                score += 100;
            }
        }

        player.MoveSnakeInCurrentDirection();

        if (player.IsOutOfBounds() || player.TailHit())
        {
            goto exit_game;
        }

        // rendering
        clear();
        border('|', '|', '-', '-', '+', '+', '+', '+');
        RenderScore(score);

        RenderFruit(fruits);
        RenderSnake(player);

        refresh();

        auto end = std::chrono::high_resolution_clock::now();

        double time_taken = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // a fraction of a second
        constexpr double time_delta = 1.0 / 8.0;

        usleep((time_delta * 1e6) - time_taken);
    }

exit_game:
    unsigned long max_score = stdscr->_maxx * stdscr->_maxy * 100;

    endwin();

    std::cout << "SCORE: " << score << std::endl;

    if (score >= max_score)
        std::cout << "YOU WIN!!!" << std::endl;

    exit(0);
}

void RenderScore(unsigned long score)
{
    mvprintw(0, 1, "%lu", score);
}

void get_user_inputs()
{
    for (;;)
    {
        switch (getch())
        {
            case 'w':
                inputs.push_back(Direction::UP);
                break;
            case 'a':
                inputs.push_back(Direction::LEFT);
                break;
            case 's':
                inputs.push_back(Direction::DOWN);
                break;
            case 'd':
                inputs.push_back(Direction::RIGHT);
                break;
        }
    }
}
