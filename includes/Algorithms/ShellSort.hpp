#pragma once

#include "Sort.hpp"

class ShellSort : public Sort
{
public:
    ShellSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
