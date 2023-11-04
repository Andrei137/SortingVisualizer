#include "../../includes/Algorithms/CombSort.hpp"

CombSort::CombSort() : Sort() {};

int CombSort::get_next_gap(int a_gap)
{
    a_gap = (a_gap * 10) / 13;
    return a_gap < 1 ? 1 : a_gap;
}

void CombSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    const int size{ (int)a_arr.size() };
    int gap{ size };
    bool swapped{ true };
    while (gap != 1 || swapped)
    {
        gap = get_next_gap(gap);
        swapped = false;
        for (int i = 0; i < size - gap; ++i)
        {
            if (a_arr[i] > a_arr[i + gap])
            {
                std::swap(a_arr[i], a_arr[i + gap]);
                swapped = true;
            }
            draw(a_window, a_arr, i, i + gap, -1);
        }
    }
}
