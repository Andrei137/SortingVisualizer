#pragma once

#include "Sort.hpp"

class GnomeSort : public Sort
{
public:
    GnomeSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
