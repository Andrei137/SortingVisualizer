#include "../../includes/Algorithms/HeapSort.hpp"

HeapSort::HeapSort() : Sort() {};

void HeapSort::heapify(sf::RenderWindow& a_window, std::vector<int>& a_arr, int a_size, int a_root)
{
    int largest{ a_root };
    int left{ 2 * a_root + 1 };
    int right{ 2 * a_root + 2 };
    if (left < a_size && a_arr[left] > a_arr[largest])
    {
        largest = left;
    }
    if (right < a_size && a_arr[right] > a_arr[largest])
    {
        largest = right;
    }
    if (largest != a_root)
    {
        std::swap(a_arr[a_root], a_arr[largest]);
        draw(a_window, a_arr, a_root, largest, -1);
        heapify(a_window, a_arr, a_size, largest);
    }
}

void HeapSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    const int size{ (int)a_arr.size() };
    for (int i = size / 2 - 1; i >= 0; --i)
    {
        heapify(a_window, a_arr, size, i);
    }
    for (int i = size - 1; i > 0; --i)
    {
        std::swap(a_arr[0], a_arr[i]);
        draw(a_window, a_arr, 0, i, -1);
        heapify(a_window, a_arr, i, 0);
    }
}
