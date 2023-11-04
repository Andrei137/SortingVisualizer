#include "../../includes/Algorithms/InsertionSort.hpp"

InsertionSort::InsertionSort() : Sort() {};

void InsertionSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    const int size{ (int)a_arr.size() };
    for (int i = 1; i < size; ++i)
    {
        int key{ a_arr[i] };
        int j{ i - 1 };
        while (j >= 0 && a_arr[j] > key)
        {
            draw(a_window, a_arr, i, j + 1, -1);
            a_arr[j + 1] = a_arr[j];
            --j;
        }
        a_arr[j + 1] = key;
    }
}
