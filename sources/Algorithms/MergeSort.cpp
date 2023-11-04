#include "../../includes/Algorithms/MergeSort.hpp"

MergeSort::MergeSort() : Sort() {};

void MergeSort::merge(sf::RenderWindow& a_window, std::vector<int>& a_arr, int a_left, int a_mid, int a_right)
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
            a_arr[k] = left[i];
            ++i;
        }
        else
        {
            a_arr[k] = right[j];
            ++j;
        }
        draw(a_window, a_arr, -1, -1, k);
        ++k;
    }
    while (i < size1)
    {
        a_arr[k] = left[i];
        ++i;
        ++k;
    }
    while (j < size2)
    {
        a_arr[k] = right[j];
        ++j;
        ++k;
    }
}

void MergeSort::merge_sort(sf::RenderWindow& a_window, std::vector<int>& a_arr, int a_left, int a_right)
{
    if (a_left >= a_right)
    {
        return;
    }
    int mid{ a_left + (a_right - a_left) / 2 };
    merge_sort(a_window, a_arr, a_left, mid);
    merge_sort(a_window, a_arr, mid + 1, a_right);
    merge(a_window, a_arr, a_left, mid, a_right);
}

void MergeSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    merge_sort(a_window, a_arr, 0, a_arr.size() - 1);
}
