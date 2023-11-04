#include "../../includes/Algorithms/SelectionSortExchange.hpp"

SelectionSortExchange::SelectionSortExchange() : Sort() {};

void SelectionSortExchange::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    const int size{ (int)a_arr.size() };
    for (int i = size - 1; i >= 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (a_arr[j] > a_arr[i])
            {
                std::swap(a_arr[i], a_arr[j]);
            }
            draw(a_window, a_arr, i, j, -1);
        }
    }
}
