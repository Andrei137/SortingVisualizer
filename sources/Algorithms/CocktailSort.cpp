#include "../../includes/Algorithms/CocktailSort.hpp"

CocktailSort::CocktailSort() : Sort() {};

void CocktailSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    const int size{ (int)a_arr.size() };
    bool swapped{ true };
    int start{ 0 };
    int end{ size - 1 };
    while (swapped)
    {
        swapped = false;
        for (int i = start; i < end; ++i)
        {
            if (a_arr[i] > a_arr[i + 1])
            {
                std::swap(a_arr[i], a_arr[i + 1]);
                swapped = true;
            }
            draw(a_window, a_arr, i, i + 1, -1);
        }
        if (!swapped)
        {
            break;
        }
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i)
        {
            if (a_arr[i] > a_arr[i + 1])
            {
                std::swap(a_arr[i], a_arr[i + 1]);
                swapped = true;
            }
            draw(a_window, a_arr, i, i + 1, -1);
        }
        ++start;
    }
}
