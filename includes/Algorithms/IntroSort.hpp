#pragma once

#include "Sort.hpp"

class IntroSort : public Sort
{
    void insertion_sort(sf::RenderWindow&, std::vector<int>&, const int*, const int*);
    int* partition(sf::RenderWindow&, std::vector<int>&, int, int);
    int* median_of_three(int*, int*, int*);
    void intro_sort(sf::RenderWindow&, std::vector<int>&, int*, int*, int);
public:
    IntroSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
