#include "../includes/Visualizer.hpp"
#include <algorithm>
#include <chrono>
#include <numeric>
#include <random>
#include <thread>

Visualizer::Visualizer() : m_arr(std::vector<int>(100)) {}

// The first window has 22 frames for some reason
// Dummy instance is used to fix this problem
void Visualizer::run_dummy_instance() 
{
    m_window.create(sf::VideoMode(1, 1), "");
    m_window.setPosition(sf::Vector2i(-10000, -10000));
    m_window.setVisible(false);
    m_window.close();
    m_window.setVisible(true);
}

void Visualizer::set_window_name(const std::string& a_name)
{
    m_window.create(sf::VideoMode(1200, 800), a_name);
}

void Visualizer::set_array_size(int a_size)
{
    m_arr.resize(a_size);
}

void Visualizer::set_algorithm(std::shared_ptr<Sort> a_algorithm)
{
    m_algorithm = a_algorithm;
}

void Visualizer::perform_sorting(char a_option)
{
    const int size{ (int)m_arr.size() };
    if (a_option == '1')
    {
        std::iota(m_arr.begin(), m_arr.end(), 1);
        std::random_device rd{};
        std::mt19937 g(rd());
        std::shuffle(m_arr.begin(), m_arr.end(), g);
    }
    else if (a_option == '2')
    {
        std::iota(m_arr.begin(), m_arr.end(), 1);
    }
    else if (a_option == '3')
    {
        std::iota(m_arr.rbegin(), m_arr.rend(), 1);
    }
    else if (a_option == '4')
    {
        std::iota(m_arr.begin(), m_arr.end(), 1);
        std::random_device rd{};
        std::mt19937 g(rd());
        std::shuffle(m_arr.begin(), m_arr.end(), g);
        std::uniform_int_distribution<> dis(size / 4, size / 2);
        std::partial_sort(m_arr.begin(), m_arr.begin() + dis(g), m_arr.end());
    }
    else if (a_option == '5')
    {
        std::iota(m_arr.begin(), m_arr.end(), 1);
        std::random_device rd{};
        std::mt19937 g(rd());
        std::sort(m_arr.begin(), m_arr.end());
        std::uniform_int_distribution<> dis(size / 2, size - 1);
        std::shuffle(m_arr.begin() + dis(g), m_arr.end(), g);
    }
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) 
    {
        std::cerr << "Error loading font" << std::endl;
        return;
    }
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    auto start_time{ std::chrono::high_resolution_clock::now() };
    m_algorithm->sort(m_window, m_arr);
    auto curr_time{ std::chrono::high_resolution_clock::now() };
    std::chrono::duration<double> elapsed = curr_time - start_time;
    text.setString("Elapsed Time: " + std::to_string(elapsed.count()));
    m_algorithm->draw(m_window, m_arr, -1, -1, -1);
    m_window.draw(text);
    m_window.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Visualizer::run(char a_option)
{
    m_window.setVerticalSyncEnabled(false);
    m_window.setFramerateLimit(144);
    perform_sorting(a_option);
    while (m_window.isOpen())
    {
        sf::Event event{};
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || 
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                m_window.close();
            }
        }
    }
}