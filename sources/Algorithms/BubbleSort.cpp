#include "../../includes/Algorithms/BubbleSort.hpp"

BubbleSort::BubbleSort() : Sort() {};

void BubbleSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    const int size{ (int)a_arr.size() };
    for (int i = 0; i < size - 1; ++i)
    {
        bool swapped{ false };
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (a_arr[j] > a_arr[j + 1])
            {
                std::swap(a_arr[j], a_arr[j + 1]);
                swapped = true;
                draw(a_window, a_arr, i, j, -1);
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}
