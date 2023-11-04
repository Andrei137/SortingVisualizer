#pragma once

#include "Sort.hpp"

class InsertionSort : public Sort
{
public:
    InsertionSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
