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

    static void start();
};