#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include "includes/snake.hpp"

void draw(std::vector<std::string>& param);

int main()
{
    bool gameover = false;
    std::vector<std::string> game_map;
    game_map.resize(25);
    for (auto& a : game_map)
    {
        a.resize(80);
    }
    for (size_t y = 0; y < game_map.size(); ++y)
    {
        for (size_t x = 0; x < game_map.at(y).size(); ++x)
        {
            game_map.at(y).at(x) = 'X';
        }
    }
    for (size_t y = 1; y < game_map.size() - 1; ++y)
    {
        for (size_t x = 1; x < game_map.at(y).size() - 1; ++x)
        {
            game_map.at(y).at(x) = ' ';
        }
    }
    Snake snake(std::make_shared< std::vector<std::string> >(game_map), gameover);
    draw(game_map);
    while (!gameover)
    {
        snake.action();
        snake.update();
        draw(game_map);
    }
    return 0;
}

void draw(std::vector<std::string> param)
{
    for (size_t y = 0; y < param.size(); ++y)
    {
        std::cout << param.at(y);
    }
}

