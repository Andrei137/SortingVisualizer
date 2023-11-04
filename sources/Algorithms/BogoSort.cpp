#include "../../includes/Algorithms/BogoSort.hpp"
#include <chrono>
#include <thread>

BogoSort::BogoSort() : Sort() {};

bool BogoSort::is_sorted(const std::vector<int>& a_arr)
{
    const int size{ (int)a_arr.size() };
    for (int i = 0; i < size - 1; ++i)
    {
        if (a_arr[i] > a_arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

void BogoSort::shuffle(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    const int size{ (int)a_arr.size() };
    for (int i = 0; i < size; ++i)
    {
        std::swap(a_arr[i], a_arr[rand() % size]);
    }
    draw(a_window, a_arr, -1, -1, -2);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

void BogoSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    while (!is_sorted(a_arr))
    {
        shuffle(a_window, a_arr);
    }
}
