#pragma once

#include "QuickSort.hpp"

class QuickSortHoare : public QuickSort
{
    int partition(sf::RenderWindow&, std::vector<int>&, int, int) override;
    int partition_random(sf::RenderWindow&, std::vector<int>&, int, int) override;
    void quick_sort(sf::RenderWindow&, std::vector<int>&, int, int) override;
};