#include "../../includes/Algorithms/QuickSortLomuto.hpp"

int QuickSortLomuto::partition(sf::RenderWindow& a_window, std::vector<int>& a_arr, int a_low, int a_high)
{
    int pivot{ a_arr[a_high] };
    int i{ a_low - 1 };
    for (int j = a_low; j < a_high; ++j)
    {
        if (a_arr[j] < pivot)
        {
            ++i;
            std::swap(a_arr[i], a_arr[j]);
            draw(a_window, a_arr, i, j, a_high);
        }
    }
    std::swap(a_arr[i + 1], a_arr[a_high]);
    draw(a_window, a_arr, i + 1, a_high, a_high);
    return i + 1;
}

int QuickSortLomuto::partition_random(sf::RenderWindow& a_window, std::vector<int>& a_arr, int a_low, int a_high)
{
    int random{ a_low + rand() % (a_high - a_low) };
    std::swap(a_arr[random], a_arr[a_high]);
    return partition(a_window, a_arr, a_low, a_high);
}

void QuickSortLomuto::quick_sort(sf::RenderWindow& a_window, std::vector<int>& a_arr, int a_low, int a_high)
{
    if (a_low < a_high)
    {
        int pivot{ partition_random(a_window, a_arr, a_low, a_high) };
        draw(a_window, a_arr, a_low, a_high, pivot);
        quick_sort(a_window, a_arr, a_low, pivot - 1);
        quick_sort(a_window, a_arr, pivot + 1, a_high);
    }
}
