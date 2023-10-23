#pragma once

#include "Algorithms/Sort.hpp"
#include <memory>

class Visualizer
{
    sf::RenderWindow m_window{};
    std::vector<int> m_arr{};
    std::shared_ptr<Sort> m_algorithm{};
    
    void draw(int, int, int);
    void perform_sorting();

public:
    explicit Visualizer(std::shared_ptr<Sort>);
    ~Visualizer() = default;

    void run();
};
