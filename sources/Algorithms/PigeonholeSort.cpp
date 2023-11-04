#include "../../includes/Algorithms/PigeonholeSort.hpp"

PigeonholeSort::PigeonholeSort() : Sort() {};

void PigeonholeSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    const int size{ (int)a_arr.size() };
    int min{ a_arr[0] };
    int max{ a_arr[0] };
    int min_index{ 0 };
    int max_index{ 0 };
    for (int i = 1; i < size; ++i)
    {
        if (a_arr[i] < min)
        {
            min = a_arr[i];
            min_index = i;
        }
        if (a_arr[i] > max)
        {
            max = a_arr[i];
            max_index = i;
        }
        draw(a_window, a_arr, min_index, max_index, i);
    }
    const int range{ max - min + 1 };
    std::vector<int> holes(range, 0);
    for (int i = 0; i < size; ++i)
    {
        ++holes[a_arr[i] - min];
    }
    int index{ 0 };
    for (int i = 0; i < range; ++i)
    {
        while (holes[i] > 0)
        {
            a_arr[index] = i + min;
            ++index;
            --holes[i];
        }
        draw(a_window, a_arr, -1, -1, index);
    }
}
