#include "includes/Visualizer.hpp"
#include "includes/QuickSort.hpp"
#include <iostream>

int main()
{
    Visualizer v{};
    v.set_algorithm(std::make_shared<QuickSort>());
    v.run();
    return 0;
}