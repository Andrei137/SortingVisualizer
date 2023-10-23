#pragma once

#include "Sort.hpp"
#include <cstdlib>

class QuickSort : public Sort
{
protected:
    void draw(sf::RenderWindow&, std::vector<int>&, int, int, int) override;
    virtual int partition(sf::RenderWindow&, std::vector<int>&, int, int) = 0;
    virtual int partition_random(sf::RenderWindow&, std::vector<int>&, int, int) = 0;
    virtual void quicksort(sf::RenderWindow&, std::vector<int>&, int, int) = 0;

public:
    QuickSort() : Sort() {};
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
