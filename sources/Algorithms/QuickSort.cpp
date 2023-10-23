#include "../../includes/Algorithms/QuickSort.hpp"

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

void QuickSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    quicksort(a_window, a_arr, 0, a_arr.size() - 1);
}
