#pragma once

#include "Sort.hpp"

class FancyCycleSort : public Sort
{
public:
    FancyCycleSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
