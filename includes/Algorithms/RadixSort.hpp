#pragma once

#include "Sort.hpp"

class RadixSort : public Sort
{
    int find_max(const std::vector<int>&);
    void count_sort(sf::RenderWindow&, std::vector<int>&, int);
public:
    RadixSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
