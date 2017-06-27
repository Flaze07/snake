#include "snake.hpp'
#include <conio.h>

Snake::Snake(std::shared_ptr< std::vector<std::string> >param, bool& boolparam) :
    layout(param), modder(boolparam)
{
    length = 5;
    parts.resize(5);
    int init_x = layout.get()->at(0).size() / 2;
    int init_y = (layout.get()->size() / 2) + (length / 2);
    for (int i = 0; i < length; ++i)
    {
        parts.at(i).pos = Vector(init_x, init_y + i);
        parts.at(i).direction = Direction::up;
        layout.get()->at(parts.at(i).pos.y).at(parts.at(i).pos.x) = '#';
    }
    cooldown = clock() + 100;
}

void Snake::action()
{
    char key = getch();
    switch(key)
    {
    case 72 : //72 is up
        parts.at(0).direction = Direction::up;
        break;
    case 80 : //80 is down
        parts.at(0).direction = Direction::down;
        break;
    case 75 : //75 is left
        parts.at(0).direction = Direction::left;
        break;
    case 77 : //77 is right
        parts.at(0).direction = Direction::right;
        break;
    }
}

void Snake::update()
{
    if (clock() >= cooldown)
    {
        for (int i = 0; i < length; ++i)
        {
            layout.get()->at(parts.at(i).pos.y).at(parts.at(i).pos.x) = ' ';
        }
        for (int i = 0; i < length; ++i)
        {
            if (parts.at(i).direction == Direction::up)
            {
                --parts.at(i).pos.y;
            }
            else if (parts.at(i).direction == Direction::down)
            {
                ++parts.at(i).pos.y;
            }
            else if (parts.at(i).direction == Direction::left)
            {
                --parts.at(i).pos.x;
            }
            else if (parts.at(i).direction == Direction::right)
            {
                ++parts.at(i).pos.x;
            }
            if (i > 0)
            {
                parts.at(i).direction = parts.at(i - 1).direction;
            }
        }
        if (layout.get()->at(parts.at(0).pos.y).at(parts.at(0).pos.x) == '.')
        {
            parts.resize(length + 1);
            if (parts.at(parts.size() - 1).pos.x - 1 == parts.at(parts.size() - 2).pos.x)
            {
                    parts.back.pos.x = parts.at(parts.size() - 1).pos.x + 1;
            }
            else
            {
                parts.back.pos.x = parts.at(parts.size() - 1).pos.x - 1;
            }
        }
        if ( (layout.get()->at(parts.at(0).pos.y).at(parts.at(i).pos.x) == 'X') || (layout.get()->at(parts.at(0).pos.y).at(parts.at(0).pos.x) == '#') )
        {
            modder = true;
        }
        for (int i = 0; i < length; ++i)
        {
            layout.get()->at(parts.at(i).pos.y).at(parts.at(i).pos.x) = '#';
        }
    }
}
