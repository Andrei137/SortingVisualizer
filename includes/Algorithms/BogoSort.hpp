#pragma once

#include "Sort.hpp"

class BogoSort : public Sort
{
    bool is_sorted(const std::vector<int>&);
    void shuffle(sf::RenderWindow&, std::vector<int>&);
public:
    BogoSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
