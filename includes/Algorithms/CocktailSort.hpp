#pragma once

#include "Sort.hpp"

class CocktailSort : public Sort
{
public:
    CocktailSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
