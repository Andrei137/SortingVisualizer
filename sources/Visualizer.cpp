#include "../includes/Visualizer.hpp"
#include "../includes/QuickSort.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>

Visualizer::Visualizer() : m_window(sf::VideoMode(1200, 800), "Sorting Visualization"), m_arr(std::vector<int>(150)) {}

void Visualizer::draw(int a_active1, int a_active2, int a_pivot)
{
    m_algorithm->draw(m_window, m_arr, a_active1, a_active2, a_pivot);
}

void Visualizer::perform_sorting()
{
    m_algorithm->sort(m_window, m_arr);
    draw(-1, -1, -1);
}

void Visualizer::set_algorithm(std::shared_ptr<SortingAlgorithm> a_algorithm) 
{
    m_algorithm = a_algorithm;
}

void Visualizer::run()
{
    std::iota(m_arr.begin(), m_arr.end(), 1);
    std::random_shuffle(m_arr.begin(), m_arr.end());
    draw(-1, -1, -1);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    perform_sorting();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    while (m_window.isOpen())
    {
        sf::Event event{};
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || 
                (event.type == sf::Event::KeyPressed && ((event.key.code == sf::Keyboard::Escape) || (event.key.code == sf::Keyboard::Q))))
            {
                m_window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
            {
                std::random_shuffle(m_arr.begin(), m_arr.end());
                draw(-1, -1, -1);
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                perform_sorting();
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
        }
    }
}