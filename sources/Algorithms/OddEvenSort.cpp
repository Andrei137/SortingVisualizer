#include "../../includes/Algorithms/OddEvenSort.hpp"

OddEvenSort::OddEvenSort() : Sort() {};

void OddEvenSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    const int size{ (int)a_arr.size() };
    bool is_sorted{ false };
    while (!is_sorted)
    {
        is_sorted = true;
        for (int i = 1; i <= size - 2; i += 2)
        {
            if (a_arr[i] > a_arr[i + 1])
            {
                draw(a_window, a_arr, -1, -1, i);
                is_sorted = false;
                std::swap(a_arr[i], a_arr[i + 1]);
            }
        }
        for (int i = 0; i <= size - 2; i += 2)
        {
            if (a_arr[i] > a_arr[i + 1])
            {
                draw(a_window, a_arr, -1, -1, i);
                is_sorted = false;
                std::swap(a_arr[i], a_arr[i + 1]);
            }
        }
    }
}
