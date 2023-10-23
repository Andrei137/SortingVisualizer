#pragma once

#include "Sort.hpp"
#include <cstdlib>

class QuickSort : public Sort
{
protected:
    virtual int partition(sf::RenderWindow&, std::vector<int>&, int, int) = 0;
    virtual int partition_random(sf::RenderWindow&, std::vector<int>&, int, int) = 0;
    virtual void quick_sort(sf::RenderWindow&, std::vector<int>&, int, int) = 0;

public:
    QuickSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
