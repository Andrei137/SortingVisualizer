#include "../../includes/Algorithms/QuickSort.hpp"

QuickSort::QuickSort() : Sort() {};

void QuickSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    quick_sort(a_window, a_arr, 0, a_arr.size() - 1);
}
