#include "../includes/Interface.hpp"
#include "../includes/Algorithms/QuickSortLomuto.hpp"
#include "../includes/Algorithms/QuickSortHoare.hpp"
#include "../includes/Algorithms/SelectionSort.hpp"
#include <iostream>
#include <set>

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

void Interface::handle_wrong_input(const std::string& a_message)
{
    rlutil::hidecursor();
    rlutil::cls();
    std::cerr << a_message;
    rlutil::msleep(2000);
    rlutil::cls();
}

char Interface::make_decision(const std::string& a_message, const std::string& a_options)
{
    while (true)
    {
        rlutil::cls();
        rlutil::showcursor();
        std::cout << a_message << "\n-> " << std::flush;
        std::string temp{};
        std::cin >> temp;
        if (temp.size() != 1 || a_options.find(temp[0]) == std::string::npos)
        {
            handle_wrong_input("Wrong input. Try again.\n");
            continue;
        }
        return temp[0];
    }
}

void Interface::start()
{
    char complexity{ '-' };
    Visualizer v{};
    v.run_dummy_instance();
    bool changed_size{ false };
    while (complexity != '0')
    {
        rlutil::cls();
        if (complexity == '-')
        {
            complexity = make_decision
            (
                "< Select complexity >\n"
                "[1] O(n^2) (Default Array Size = 50]\n"
                "[2] O(n * log_n) (Default Array Size = 150)\n"
                "[3] Change array size\n"
                "[0] Exit\n",
                "0123"
            );
        }
        if (complexity == '0')
        {
            rlutil::cls();
            destroy_instance();
            return;
        }
        else if (complexity == '3')
        {
            rlutil::cls();
            std::cout << "Enter array size: ";
            int size{};
            std::cin >> size;
            v.set_array_size(size);
            changed_size = true;
            complexity = '-';
        }
        else
        {
            char algorithm{};
            if (complexity == '1')
            {
                if (!changed_size)
                {
                    v.set_array_size(50);
                }
                algorithm = make_decision
                (
                    "< Select algorithm >\n"
                    "[1] Selection Sort\n"
                    "[0] Go Back\n",
                    "01"
                );
                if (algorithm == '0')
                {
                    complexity = '-';
                    continue;
                }
                else if (algorithm == '1')
                {
                    v.set_window_name("Selection Sort");
                    v.set_algorithm(std::make_shared<SelectionSort>());
                }
                complexity = '1';
            }
            if (complexity == '2')
            {
                if (!changed_size)
                {
                    v.set_array_size(250);
                }
                algorithm = make_decision
                (
                    "< Select algorithm >\n"
                    "[1] Quick Sort (Lomuto partition scheme)\n"
                    "[2] Quick Sort (Hoare partition scheme)\n"
                    "[0] Go Back\n",
                    "012"
                );
                if (algorithm == '0')
                {
                    complexity = '-';
                    continue;
                }
                else if (algorithm == '1')
                {
                    v.set_window_name("Quick Sort (Lomuto partition scheme)");
                    v.set_algorithm(std::make_shared<QuickSortLomuto>());
                }
                else if (algorithm == '2')
                {
                    v.set_window_name("Quick Sort (Hoare partition scheme)");
                    v.set_algorithm(std::make_shared<QuickSortHoare>());
                }
                complexity = '2';
            }
            v.run();
        }
    }
}
