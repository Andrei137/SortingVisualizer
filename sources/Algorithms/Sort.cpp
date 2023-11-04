#include "../../includes/Algorithms/Sort.hpp"

void Sort::draw(sf::RenderWindow& a_window, std::vector<int>& a_arr, int a_active1, int a_active2, int a_pivot)
{
    a_window.clear(sf::Color::Black);
    float width{ (float)a_window.getSize().x / a_arr.size() };
    float height_ratio{ (float)a_window.getSize().y / (int)a_arr.size() };
    for (int i = 0; i < (int)a_arr.size(); ++i)
    {
        sf::RectangleShape bar(sf::Vector2f(width - 1, a_arr[i] * height_ratio));
        bar.setPosition(i * width, a_window.getSize().y - a_arr[i] * height_ratio);
        if (a_active1 == a_active2 && a_active1 == a_pivot && a_active1 == -1)
        {
            bar.setFillColor(sf::Color::Green);
        }
        else if (i == a_pivot)
        {
            bar.setFillColor(sf::Color::Blue);
        }
        else
        {
            bar.setFillColor((i == a_active1 || i == a_active2) ? sf::Color::Red : sf::Color::White);
        }
        a_window.draw(bar);
    }
    if (a_active1 == a_active2 && a_active1 == a_pivot && a_active1 == -1)
    {
        return;
    }
    a_window.display();
}