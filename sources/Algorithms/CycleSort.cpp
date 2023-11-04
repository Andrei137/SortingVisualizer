#include "../../includes/Algorithms/CycleSort.hpp"

CycleSort::CycleSort() : Sort() {};

void CycleSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    const int size{ (int)a_arr.size() };
    int writes{ 0 };
    for (int cycle_start = 0; cycle_start <= size - 2; ++cycle_start)
    {
        int item{ a_arr[cycle_start] };
        int pos{ cycle_start };
        for (int i = cycle_start + 1; i < size; ++i)
        {
            if (a_arr[i] < item)
            {
                ++pos;
                draw(a_window, a_arr, -1, -1, pos);
            }
        }
        if (pos == cycle_start)
        {
            continue;
        }
        while (item == a_arr[pos])
        {
            ++pos;
        }
        if (pos != cycle_start)
        {
            std::swap(item, a_arr[pos]);
            ++writes;
        }
        while (pos != cycle_start)
        {
            pos = cycle_start;
            for (int i = cycle_start + 1; i < size; ++i)
            {
                if (a_arr[i] < item)
                {
                    ++pos;
                    draw(a_window, a_arr, -1, -1, pos);
                }
            }
            while (item == a_arr[pos])
            {
                ++pos;
            }
            draw(a_window, a_arr, -1, -1, pos);
            std::swap(item, a_arr[pos]);
            ++writes;
        }
    }
}
