#pragma once

#include "Sort.hpp"

class BubbleSort : public Sort
{
public:
    BubbleSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
