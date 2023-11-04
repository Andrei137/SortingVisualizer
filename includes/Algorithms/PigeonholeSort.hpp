#pragma once

#include "Sort.hpp"

class PigeonholeSort : public Sort
{
public:
    PigeonholeSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
