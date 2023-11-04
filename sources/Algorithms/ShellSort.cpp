#include "../../includes/Algorithms/ShellSort.hpp"

ShellSort::ShellSort() : Sort() {};

void ShellSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    const int size{ (int)a_arr.size() };
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; ++i)
        {
            int temp{ a_arr[i] };
            int j{};
            for (j = i; j >= gap && a_arr[j - gap] > temp; j -= gap)
            {
                a_arr[j] = a_arr[j - gap];
            }
            a_arr[j] = temp;
            draw(a_window, a_arr, j, i, -1);


            
        }
    }
}
