#pragma once

#include "Algorithms/Sort.hpp"
#include <memory>
#include <rlutil.h>

class Visualizer
{
    sf::RenderWindow m_window{};
    std::vector<int> m_arr{};
    std::shared_ptr<Sort> m_algorithm{};

    void perform_sorting(char);

public:
    Visualizer();
    ~Visualizer() = default;

    void set_window_name(const std::string&);
    void set_array_size(int);
    void set_algorithm(std::shared_ptr<Sort>);

    void run_dummy_instance();
    void run(char);
};
