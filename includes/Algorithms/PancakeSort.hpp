#pragma once

#include "Sort.hpp"

class PancakeSort : public Sort
{
    void flip(sf::RenderWindow&, std::vector<int>&, int);
    int find_max(const std::vector<int>&, int);
public:
    PancakeSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
