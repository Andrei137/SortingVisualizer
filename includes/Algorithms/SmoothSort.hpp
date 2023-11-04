#pragma once

#include "Sort.hpp"

class SmoothSort : public Sort
{
    int leonardo(int);
    void heapify(sf::RenderWindow&, std::vector<int>&, int, int);
public:
    SmoothSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
