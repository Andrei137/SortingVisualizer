#include "../../includes/Algorithms/QuickSortHoare.hpp"

int QuickSortHoare::partition(sf::RenderWindow& a_window, std::vector<int>& a_arr, int a_low, int a_high)
{
    int pivot{ a_arr[a_low] };
    int i{ a_low - 1 };
    int j{ a_high + 1 };
    while (true)
    {
        do
        {
            ++i;
            draw(a_window, a_arr, i, j, a_low);
        } while (a_arr[i] < pivot);
        do
        {
            --j;
            draw(a_window, a_arr, i, j, a_low);
        } while (a_arr[j] > pivot);
        if (i >= j)
        {
            return j;
        }
        std::swap(a_arr[i], a_arr[j]);
    }
}

int QuickSortHoare::partition_random(sf::RenderWindow& a_window, std::vector<int>& a_arr, int a_low, int a_high)
{
    int random{ a_low + rand() % (a_high - a_low) };
    std::swap(a_arr[random], a_arr[a_low]);
    return partition(a_window, a_arr, a_low, a_high);
}

void QuickSortHoare::quick_sort(sf::RenderWindow& a_window, std::vector<int>& a_arr, int a_low, int a_high)
{
    if (a_low < a_high)
    {
        int pivot{ partition_random(a_window, a_arr, a_low, a_high) };
        draw(a_window, a_arr, a_low, a_high, pivot);
        quick_sort(a_window, a_arr, a_low, pivot);
        quick_sort(a_window, a_arr, pivot + 1, a_high);
    }
}
