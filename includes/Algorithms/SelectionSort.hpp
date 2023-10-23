#pragma once

#include "Sort.hpp"
#include <cstdlib>

class SelectionSort : public Sort
{
public:
    SelectionSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
