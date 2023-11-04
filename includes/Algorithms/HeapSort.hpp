#pragma once

#include "Sort.hpp"

class HeapSort : public Sort
{
    void heapify(sf::RenderWindow&, std::vector<int>&, int, int);
public:
    HeapSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
