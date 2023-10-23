#include "QuickSort.hpp"

class QuickSortHoare : public QuickSort
{
    int partition(sf::RenderWindow&, std::vector<int>&, int, int) override;
    int partition_random(sf::RenderWindow&, std::vector<int>&, int, int) override;
    void quicksort(sf::RenderWindow&, std::vector<int>&, int, int) override;
};