#include "../../includes/Algorithms/PancakeSort.hpp"

PancakeSort::PancakeSort() : Sort() {};

void PancakeSort::flip(sf::RenderWindow& a_window, std::vector<int>& a_arr, int a_i)
{
    int start{ 0 };
    while (start < a_i)
    {
        draw(a_window, a_arr, a_i, start, -1);
        std::swap(a_arr[start], a_arr[a_i]);
        ++start;
        --a_i;
    }
}

int PancakeSort::find_max(const std::vector<int>& a_arr, int a_size)
{
    int max_index{ 0 };
    for (int i = 1; i < a_size; ++i)
    {
        if (a_arr[i] > a_arr[max_index])
        {
            max_index = i;
        }
    }
    return max_index;
}

void PancakeSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    const int size{ (int)a_arr.size() };
    for (int curr_size = size; curr_size > 1; --curr_size)
    {
        int max_index{ find_max(a_arr, curr_size) };
        if (max_index != curr_size - 1)
        {
            flip(a_window, a_arr, max_index);
            flip(a_window, a_arr, curr_size - 1);
        }
    }
}
