#pragma once

#include "Sort.hpp"

class SelectionSortExchange : public Sort
{
public:
    SelectionSortExchange();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
