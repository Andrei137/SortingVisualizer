#include "../../includes/Algorithms/IntroSort.hpp"
#include <cmath>

IntroSort::IntroSort() : Sort() {};

void IntroSort::insertion_sort(sf::RenderWindow& a_window, std::vector<int>& a_arr, const int* a_begin, const int* a_end)
{
    int left{ static_cast<int>(a_begin - &a_arr[0]) };
    int right{ static_cast<int>(a_end - &a_arr[0]) };
    for (int i = left + 1; i <= right; ++i)
    {
        int key{ a_arr[i] };
        int j{ i - 1 };
        while (j >= left && a_arr[j] > key)
        {
            a_arr[j + 1] = a_arr[j];
            --j;
            draw(a_window, a_arr, i, j, -1);
        }
        a_arr[j + 1] = key;
    }

}

int* IntroSort::partition(sf::RenderWindow& a_window, std::vector<int>& a_arr, int a_low, int a_high)
{
    int pivot{ a_arr[a_high] };
    int i{ a_low - 1 };
    for (int j = a_low; j < a_high; ++j)
    {
        if (a_arr[j] < pivot)
        {
            ++i;
            std::swap(a_arr[i], a_arr[j]);
            draw(a_window, a_arr, i, j, a_high);
        }
    }
    std::swap(a_arr[i + 1], a_arr[a_high]);
    return &a_arr[i + 1];
}

int* IntroSort::median_of_three(int* a_a, int* a_b, int* a_c)
{
    if (*a_a < *a_b && *a_b < *a_c) 
    {
        return (a_b); 
    }
    if (*a_a < *a_c && *a_c <= *a_b) 
    {
        return (a_c); 
    }
    if (*a_b <= *a_a && *a_a < *a_c) 
    {
        return (a_a); 
    }
    if (*a_b < *a_c && *a_c <= *a_a) 
    {
        return (a_c); 
    }
    if (*a_c <= *a_a && *a_a < *a_b) 
    {
        return (a_a); 
    }
    return (a_b); 
}

void IntroSort::intro_sort(sf::RenderWindow& a_window, std::vector<int>& a_arr, int* a_begin, int* a_end, int a_depth_limit)
{
    int size{ static_cast<int>(a_end - a_begin) };
    if (size < 16)
    {
        insertion_sort(a_window, a_arr, a_begin, a_end);
        return;
    }
    if (a_depth_limit == 0)
    {
        std::make_heap(a_begin, a_end + 1);
        std::sort_heap(a_begin, a_end + 1);
        return;
    }
    int* pivot{ median_of_three(a_begin, a_begin + size / 2, a_end) };
    std::swap(*pivot, *a_end);
    pivot = partition(a_window, a_arr, a_begin - &a_arr[0], a_end - &a_arr[0]);
    intro_sort(a_window, a_arr, a_begin, pivot - 1, a_depth_limit - 1);
    intro_sort(a_window, a_arr, pivot + 1, a_end, a_depth_limit - 1);
}

void IntroSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    const int size{ (int)a_arr.size() };
    int depth_limit{ static_cast<int>(2 * log(size)) };
    int* begin{ &a_arr[0] };
    int* end{ &a_arr[size - 1] };
    intro_sort(a_window, a_arr, begin, end, depth_limit);
}
