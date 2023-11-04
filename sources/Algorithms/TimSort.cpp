#include "../../includes/Algorithms/TimSort.hpp"

TimSort::TimSort() : Sort() {};

void TimSort::insertion_sort(sf::RenderWindow& a_window, std::vector<int>& a_arr, int a_left, int a_right)
{
    for (int i = a_left + 1; i <= a_right; ++i)
    {
        int key{ a_arr[i] };
        int j{ i - 1 };
        while (j >= a_left && a_arr[j] > key)
        {
            a_arr[j + 1] = a_arr[j];
            --j;
            draw(a_window, a_arr, i, j + 1, -1);
        }
        a_arr[j + 1] = key;
    }
}

void TimSort::merge(sf::RenderWindow& a_window, std::vector<int>& a_arr, int a_left, int a_mid, int a_right)
{
    int size1{ a_mid - a_left + 1 };
    int size2{ a_right - a_mid };
    std::vector<int> left(size1);
    std::vector<int> right(size2);
    for (int i = 0; i < size1; ++i)
    {
        left[i] = a_arr[a_left + i];
    }
    for (int i = 0; i < size2; ++i)
    {
        right[i] = a_arr[a_mid + 1 + i];
    }
    int i{ 0 }, j{ 0 }, k{ a_left };
    while (i < size1 && j < size2)
    {
        if (left[i] <= right[j])
        {
            a_arr[k++] = left[i++];
        }
        else
        {
            a_arr[k++] = right[j++];
        }
        draw(a_window, a_arr, -1, -1, k);
    }
    while (i < size1)
    {
        a_arr[k++] = left[i++];
    }
    while (j < size2)
    {
        a_arr[k++] = right[j++];
    }
}

void TimSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    const int RUN{ 32 };
    const int size{ (int)a_arr.size() };
    for (int i = 0; i < size; i += RUN)
    {
        insertion_sort(a_window, a_arr, i, std::min((i + RUN - 1), (size - 1)));
    }
    for (int len = RUN; len < size; len *= 2)
    {
        for (int left = 0; left < size; left += 2 * len)
        {
            int mid{ left + len - 1 };
            int right{ std::min((left + 2 * len - 1), (size - 1)) };
            if (mid < right)
            {
                merge(a_window, a_arr, left, mid, right);
            }
        }
    }
}
