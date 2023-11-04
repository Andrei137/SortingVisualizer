#include "../../includes/Algorithms/SelectionSort.hpp"

SelectionSort::SelectionSort() : Sort() {};

void SelectionSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    const int size{ (int)a_arr.size() };
    for (int i = 0; i < size - 1; ++i)
    {
        int min_index{ i };
        for (int j = i + 1; j < size; ++j)
        {
            if (a_arr[j] < a_arr[min_index])
            {
                min_index = j;
            }
            draw(a_window, a_arr, i, j, min_index);
        }
        std::swap(a_arr[min_index], a_arr[i]);
    }
}
