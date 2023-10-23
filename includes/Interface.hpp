#pragma once

#include "Visualizer.hpp"

class Interface
{
private:
    static Interface* m_instance;

    Interface() = default;

    static void destroy_instance();

public:
    Interface(const Interface&) = delete;
    Interface& operator=(const Interface&) = delete;
    static Interface& get_instance();
    ~Interface() = default;

    static void handle_wrong_input(const std::string&);
    static char make_decision(const std::string&, const std::string&);
    static void start();
};