#pragma once

#include "Sort.hpp"

class CycleSort : public Sort
{
public:
    CycleSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
