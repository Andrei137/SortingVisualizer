#pragma once

#include "Sort.hpp"

class TimSort : public Sort
{
    void insertion_sort(sf::RenderWindow&, std::vector<int>&, int, int);
    void merge(sf::RenderWindow&, std::vector<int>&, int, int, int);
public:
    TimSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
