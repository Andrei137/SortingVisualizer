#include "../../includes/Algorithms/FancyCycleSort.hpp"

FancyCycleSort::FancyCycleSort() : Sort() {};

void FancyCycleSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    const int size{ (int)a_arr.size() };
    int i{ 0 };
    while (i < size)
    {
        int correct{ a_arr[i] - 1 };
        if (a_arr[i] != a_arr[correct])
        {
            draw(a_window, a_arr, i, correct, -1);
            std::swap(a_arr[i], a_arr[correct]);
        }
        else
        {
            ++i;
        }

    }
}
