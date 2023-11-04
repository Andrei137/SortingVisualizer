#include "../../includes/Algorithms/GnomeSort.hpp"

GnomeSort::GnomeSort() : Sort() {};

void GnomeSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    const int size{ (int)a_arr.size() };
    int index{ 0 };
    while (index < size)
    {
        if (index == 0)
        {
            ++index;
        }
        if (a_arr[index] >= a_arr[index - 1])
        {
            ++index;
        }
        else
        {
            std::swap(a_arr[index], a_arr[index - 1]);
            --index;
        }
        draw(a_window, a_arr, -1, -1, index);
    }
}
