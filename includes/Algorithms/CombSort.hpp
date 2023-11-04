#pragma once

#include "Sort.hpp"

class CombSort : public Sort
{
    int get_next_gap(int);
public:
    CombSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
