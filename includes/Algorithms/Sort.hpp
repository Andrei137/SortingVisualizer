#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Sort
{
public:
    Sort() = default;
    virtual ~Sort() = default;

    virtual void sort(sf::RenderWindow&, std::vector<int>&) = 0;
    void draw(sf::RenderWindow&, std::vector<int>&, int, int, int);
};