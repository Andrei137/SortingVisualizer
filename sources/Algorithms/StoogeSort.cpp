#include "../../includes/Algorithms/StoogeSort.hpp"

StoogeSort::StoogeSort() : Sort() {};

void StoogeSort::stooge_sort(sf::RenderWindow& a_window, std::vector<int>& a_arr, int a_low, int a_high)
{
    if (a_low >= a_high)
    {
        return;
    }
    if (a_arr[a_low] > a_arr[a_high])
    {
        std::swap(a_arr[a_low], a_arr[a_high]);
        draw(a_window, a_arr, a_low, a_high, -1);
    }
    if (a_high - a_low + 1 > 2)
    {
        int t{ (a_high - a_low + 1) / 3 };
        stooge_sort(a_window, a_arr, a_low, a_high - t);
        stooge_sort(a_window, a_arr, a_low + t, a_high);
        stooge_sort(a_window, a_arr, a_low, a_high - t);
    }
}

void StoogeSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    stooge_sort(a_window, a_arr, 0, (int)a_arr.size() - 1);
}
