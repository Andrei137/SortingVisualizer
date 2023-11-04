#include "../../includes/Algorithms/SmoothSort.hpp"

SmoothSort::SmoothSort() : Sort() {};

int SmoothSort::leonardo(int a_k)
{
    if (a_k < 2)
    {
        return 1;
    }
    return leonardo(a_k - 1) + leonardo(a_k - 2) + 1;
}

void SmoothSort::heapify(std::vector<int>& a_arr, int a_size, int a_root)
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
        heapify(a_arr, a_size, largest);
    }
}

void SmoothSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    const int size{ (int)a_arr.size() };
    int p{ size - 1 };
    int q{ p };
    int r{ 0 };
    while (p > 0)
    {
        if ((r & 0x03) == 0)
        {
            heapify(a_arr, r, q);
        }
        if (leonardo(r) == p)
        {
            ++r;
        }
        else
        {
            --r;
            q -= leonardo(r);
            heapify(a_arr, r, q);
            q = r - 1;
            ++r;
        }
        std::swap(a_arr[0], a_arr[p]);
        --p;
    }
    for (int i = 0; i < size - 1; ++i)
    {
        int j{ i + 1 };
        draw(a_window, a_arr, -1, -1, i);
        while (j > 0 && a_arr[j] < a_arr[j - 1])
        {
            std::swap(a_arr[j], a_arr[j - 1]);
            --j;
        }
        draw(a_window, a_arr, -1, -1, i);
    }
}

