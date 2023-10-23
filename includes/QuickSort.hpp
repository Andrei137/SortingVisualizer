#pragma once

#include "SortingAlgorithm.hpp"

class QuickSort : public SortingAlgorithm
{
private:
    void draw(sf::RenderWindow&, std::vector<int>&, int, int, int) override;
    int partition(sf::RenderWindow&, std::vector<int>&, int, int);
    int partition_random(sf::RenderWindow&, std::vector<int>&, int, int);
    void quicksort(sf::RenderWindow&, std::vector<int>&, int, int);

public:
    QuickSort() : SortingAlgorithm() {};
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
