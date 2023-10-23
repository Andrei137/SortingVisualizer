#pragma once

#include "SortingAlgorithm.hpp"
#include <memory>

class Visualizer
{
    sf::RenderWindow m_window{};
    std::vector<int> m_arr{};
    std::shared_ptr<SortingAlgorithm> m_algorithm{};
    
    void draw(int, int, int);
    void perform_sorting();

public:
    explicit Visualizer(std::shared_ptr<SortingAlgorithm>);
    ~Visualizer() = default;

    void set_algorithm(std::shared_ptr<SortingAlgorithm>);
    void run();
};
