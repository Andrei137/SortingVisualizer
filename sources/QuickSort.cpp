#include "../includes/QuickSort.hpp"
#include <cstdlib>

void QuickSort::draw(sf::RenderWindow& a_window, std::vector<int>& a_arr, int a_active1, int a_active2, int a_pivot)
{
    a_window.clear(sf::Color::Black);
    float width{ (float)a_window.getSize().x / a_arr.size() };
    float height_ratio{ (float)a_window.getSize().y / *std::max_element(a_arr.begin(), a_arr.end()) };
    for (int i = 0; i < (int)a_arr.size(); ++i)
    {
        sf::RectangleShape bar(sf::Vector2f(width - 1, a_arr[i] * height_ratio));
        bar.setPosition(i * width, a_window.getSize().y - a_arr[i] * height_ratio);
        if (i == a_pivot)
        {
            bar.setFillColor(sf::Color::Green);
        }
        else
        {
            bar.setFillColor((i == a_active1 || i == a_active2) ? sf::Color::Red : sf::Color::White);
        }
        a_window.draw(bar);
    }
    a_window.display();
}

int QuickSort::partition(sf::RenderWindow& a_window, std::vector<int>& a_arr, int a_low, int a_high)
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
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
    }
    std::swap(a_arr[i + 1], a_arr[a_high]);
    draw(a_window, a_arr, i + 1, a_high, a_high);
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    return i + 1;
}

int QuickSort::partition_random(sf::RenderWindow& a_window, std::vector<int>& a_arr, int a_low, int a_high)
{
    int random{ a_low + rand() % (a_high - a_low) };
    std::swap(a_arr[random], a_arr[a_high]);
    return partition(a_window, a_arr, a_low, a_high);
}

void QuickSort::quicksort(sf::RenderWindow& a_window, std::vector<int>& a_arr, int a_low, int a_high)
{
    if (a_low < a_high)
    {
        int pivot{ partition_random(a_window, a_arr, a_low, a_high) };
        draw(a_window, a_arr, a_low, a_high, pivot);
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        quicksort(a_window, a_arr, a_low, pivot - 1);
        quicksort(a_window, a_arr, pivot + 1, a_high);
    }
}

void QuickSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    quicksort(a_window, a_arr, 0, a_arr.size() - 1);
}
