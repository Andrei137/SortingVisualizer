#pragma once

#include "Sort.hpp"

class OddEvenSort : public Sort
{
public:
    OddEvenSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
