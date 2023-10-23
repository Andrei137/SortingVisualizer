#pragma once

#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <vector>

class Sort
{
public:
    Sort() = default;
    virtual ~Sort() = default;

    virtual void sort(sf::RenderWindow&, std::vector<int>&) = 0;
    virtual void draw(sf::RenderWindow&, std::vector<int>&, int, int, int) = 0;
};