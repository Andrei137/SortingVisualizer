#pragma once

#include "Sort.hpp"
#include <cstdlib>

class QuickSort : public SortingAlgorithm
{
protected:
    void draw(sf::RenderWindow&, std::vector<int>&, int, int, int) override;
    virtual int partition(sf::RenderWindow&, std::vector<int>&, int, int) = 0;
    virtual int partition_random(sf::RenderWindow&, std::vector<int>&, int, int) = 0;
    virtual void quicksort(sf::RenderWindow&, std::vector<int>&, int, int) = 0;

public:
    QuickSort() : SortingAlgorithm() {};
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
