#ifndef SNAKE_HPP_INCLUDED
#define SNAKE_HPP_INCLUDED

#include<vector>
#include<string>
#include <ctime>
#include <memory>
#include "vector.hpp"

//reminder, the first at is y and second is x

class Snake
{
private :
    enum class Direction {up, down, left, right};
    std::shared_ptr< std::vector<std::string> > layout;
    int length;
    struct _parts
    {
        Vector pos;
        Direction direction;
    };
    std::vector<_parts> parts;
    time_t cooldown;
    bool& modder;
public :
    Snake(std::shared_ptr< std::vector<std::string> > param, bool& boolparam);
    void action();
    void update();
};

#endif // SNAKE_HPP_INCLUDED
