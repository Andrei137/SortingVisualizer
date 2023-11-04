#include "../../includes/Algorithms/RadixSort.hpp"

RadixSort::RadixSort() : Sort() {};

int RadixSort::find_max(const std::vector<int>& a_arr)
{
    const int size{ (int)a_arr.size() };
    int max{ a_arr[0] };
    for (int i = 1; i < size; ++i)
    {
        if (a_arr[i] > max)
        {
            max = a_arr[i];
        }
    }
    return max;
}

void RadixSort::count_sort(sf::RenderWindow& a_window, std::vector<int>& a_arr, int a_exp)
{
    const int size{ (int)a_arr.size() };
    std::vector<int> output(size);
    std::vector<int> count(10, 0);
    for (int i = 0; i < size; ++i)
    {
        ++count[(a_arr[i] / a_exp) % 10];
    }
    for (int i = 1; i < 10; ++i)
    {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; --i)
    {
        output[count[(a_arr[i] / a_exp) % 10] - 1] = a_arr[i];
        --count[(a_arr[i] / a_exp) % 10];
    }
    for (int i = 0; i < size; ++i)
    {
        a_arr[i] = output[i];
        draw(a_window, a_arr, -1, -1, i);
    }
}

void RadixSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    const int max{ find_max(a_arr) };
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        count_sort(a_window, a_arr, exp);
    }
}