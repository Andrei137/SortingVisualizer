#pragma once

#include "Sort.hpp"

class MergeSort : public Sort
{
    void merge(sf::RenderWindow&, std::vector<int>&, int, int, int);
    void merge_sort(sf::RenderWindow&, std::vector<int>&, int, int);
public:
    MergeSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
