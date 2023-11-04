#pragma once

#include "Sort.hpp"

class StoogeSort : public Sort
{
    void stooge_sort(sf::RenderWindow&, std::vector<int>&, int, int);
public:
    StoogeSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
