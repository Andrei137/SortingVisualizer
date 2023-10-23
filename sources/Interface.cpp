#include "../includes/Interface.hpp"
#include "../includes/QuickSortLomuto.hpp"
#include "../includes/QuickSortHoare.hpp"
#include <iostream>
#include <rlutil.h>

Interface* Interface::m_instance{ nullptr };

Interface& Interface::get_instance()
{
    if (m_instance == nullptr)
    {
        m_instance = new Interface();
    }
    return *m_instance;
}

void Interface::destroy_instance()
{
    m_instance = nullptr;
}

void Interface::start()
{
    int choice{ -1 };
    while (choice == -1)
    {
        rlutil::cls();
        std::cout << "Select sorting algorithm:\n\n";
        std::cout << "[1] QuickSortLomuto\n";
        std::cout << "[2] QuickSortHoare\n";
        std::cout << "[0] Exit\n\n";
        std::cout << "-> " << std::flush;
        std::cin >> choice;
        if (choice == 0)
        {
            return;
        }
        else if (choice == 1)
        {
            Visualizer v(std::make_shared<QuickSortLomuto>());
            v.run();
        }
        else if (choice == 2)
        {
            Visualizer v(std::make_shared<QuickSortHoare>());
            v.run();
        }
        else
        {
            rlutil::cls();
        }
        choice = -1;
    }
}
