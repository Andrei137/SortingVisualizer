#include "../includes/Interface.hpp"
#include "../includes/Algorithms/BogoSort.hpp"
#include "../includes/Algorithms/BubbleSort.hpp"
#include "../includes/Algorithms/CocktailSort.hpp"
#include "../includes/Algorithms/CombSort.hpp"
#include "../includes/Algorithms/CycleSort.hpp"
#include "../includes/Algorithms/FancyCycleSort.hpp"
#include "../includes/Algorithms/GnomeSort.hpp"
#include "../includes/Algorithms/HeapSort.hpp"
#include "../includes/Algorithms/InsertionSort.hpp"
#include "../includes/Algorithms/IntroSort.hpp"
#include "../includes/Algorithms/MergeSort.hpp"
#include "../includes/Algorithms/OddEvenSort.hpp"
#include "../includes/Algorithms/PancakeSort.hpp"
#include "../includes/Algorithms/PigeonholeSort.hpp"
#include "../includes/Algorithms/QuickSortHoare.hpp"
#include "../includes/Algorithms/QuickSortLomuto.hpp"
#include "../includes/Algorithms/RadixSort.hpp"
#include "../includes/Algorithms/SelectionSort.hpp"
#include "../includes/Algorithms/SelectionSortExchange.hpp"
#include "../includes/Algorithms/ShellSort.hpp"
#include "../includes/Algorithms/SmoothSort.hpp"
#include "../includes/Algorithms/StoogeSort.hpp"
#include "../includes/Algorithms/TimSort.hpp"
#include "../includes/Algorithms/TreeSort.hpp"
#include <iostream>

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
    rlutil::msleep(750);
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
    char array_order{ '1' };
    while (complexity != '0')
    {
        rlutil::cls();
        if (complexity == '-')
        {
            complexity = make_decision
            (
                "< Select complexity >\n\n"
                "[1] O(n^2) (Default Array Size = 100)\n"
                "[2] O(n * log_n) (Default Array Size = 300)\n"
                "[3] Other complexities\n"
                "[4] Change array size\n"
                "[5] Change array initial order (Default = Random Shuffle)\n"
                "[0] Exit\n",
                "012345"
            );
        }
        if (complexity == '0')
        {
            rlutil::cls();
            destroy_instance();
            return;
        }
        else if (complexity == '4')
        {
            rlutil::cls();
            std::cout << "Enter array size (0 to go back): ";
            int size{};
            std::cin >> size;
            if (size != 0)
            {
                v.set_array_size(size);
                changed_size = true;
            }
            complexity = '-';
        }
        else if (complexity == '5')
        {
            rlutil::cls();
            array_order = make_decision
            (
                "< Select initial order >\n\n"
                "[1] Random Shuffle\n"
                "[2] Partially Sorted\n"
                "[3] Nearly Sorted\n"
                "[4] Decreasing Order\n"
                "[5] Incresing Order\n"
                "[0] Go Back\n",
                "012345"
            );
            if (array_order == '0')
            {
                array_order = '1';
            }
            complexity = '-';
        }
        else
        {
            char algorithm{};
            if (complexity == '1')
            {
                if (!changed_size)
                {
                    v.set_array_size(100);
                }
                algorithm = make_decision
                (
                    "< Select algorithm >\n\n"
                    "[1] Bubble Sort\n"
                    "[2] Cocktail Sort\n"
                    "[3] Cycle Sort\n"
                    "[4] Gnome Sort\n"
                    "[5] Insertion Sort\n"
                    "[6] OddEven Sort\n"
                    "[7] Pancake Sort\n"
                    "[8] Selection Sort\n"
                    "[9] Selection Sort (Exchange Variantion)\n"
                    "[0] Go Back\n",
                    "0123456789"
                );
                if (algorithm == '0')
                {
                    complexity = '-';
                    continue;
                }
                else if (algorithm == '1')
                {
                    v.set_window_name("Bubble Sort");
                    v.set_algorithm(std::make_shared<BubbleSort>());
                }
                else if (algorithm == '2')
                {
                    v.set_window_name("Cocktail Sort");
                    v.set_algorithm(std::make_shared<CocktailSort>());
                }
                else if (algorithm == '3')
                {
                    v.set_window_name("Cycle Sort");
                    v.set_algorithm(std::make_shared<CycleSort>());
                }
                else if (algorithm == '4')
                {
                    v.set_window_name("Gnome Sort");
                    v.set_algorithm(std::make_shared<GnomeSort>());
                }
                else if (algorithm == '5')
                {
                    v.set_window_name("Insertion Sort");
                    v.set_algorithm(std::make_shared<InsertionSort>());
                }
                else if (algorithm == '6')
                {
                    v.set_window_name("Odd-Even Sort");
                    v.set_algorithm(std::make_shared<OddEvenSort>());
                }
                else if (algorithm == '7')
                {
                    v.set_window_name("Pancake Sort");
                    v.set_algorithm(std::make_shared<PancakeSort>());
                }
                else if (algorithm == '8')
                {
                    v.set_window_name("Selection Sort");
                    v.set_algorithm(std::make_shared<SelectionSort>());
                }
                else if (algorithm == '9')
                {
                    v.set_window_name("Selection Sort (Exchange Variation)");
                    v.set_algorithm(std::make_shared<SelectionSortExchange>());
                }
                complexity = '1';
            }
            if (complexity == '2')
            {
                if (!changed_size)
                {
                    v.set_array_size(300);
                }
                algorithm = make_decision
                (
                    "< Select algorithm >\n\n"
                    "[1] Heap Sort\n"
                    "[2] Intro Sort\n"
                    "[3] Merge Sort\n"
                    "[4] Quick Sort (Lomuto partition scheme)\n"
                    "[5] Quick Sort (Hoare partition scheme)\n"
                    "[6] Shell Sort\n"
                    "[7] Smooth Sort\n"
                    "[8] Tim Sort\n" 
                    "[9] Tree Sort\n"
                    "[0] Go Back\n",
                    "0123456789"
                );
                if (algorithm == '0')
                {
                    complexity = '-';
                    continue;
                }
                else if (algorithm == '1')
                {
                    v.set_window_name("Heap Sort");
                    v.set_algorithm(std::make_shared<HeapSort>());
                }
                else if (algorithm == '2')
                {
                    v.set_window_name("Intro Sort");
                    v.set_algorithm(std::make_shared<IntroSort>());
                }
                else if (algorithm == '3')
                {
                    v.set_window_name("Merge Sort");
                    v.set_algorithm(std::make_shared<MergeSort>());
                }
                else if (algorithm == '4')
                {
                    v.set_window_name("Quick Sort (Lomuto partition scheme)");
                    v.set_algorithm(std::make_shared<QuickSortLomuto>());
                }
                else if (algorithm == '5')
                {
                    v.set_window_name("Quick Sort (Hoare partition scheme)");
                    v.set_algorithm(std::make_shared<QuickSortHoare>());
                }
                else if (algorithm == '6')
                {
                    v.set_window_name("Shell Sort");
                    v.set_algorithm(std::make_shared<ShellSort>());
                }
                else if (algorithm == '7')
                {
                    v.set_window_name("Smooth Sort");
                    v.set_algorithm(std::make_shared<SmoothSort>());
                }
                else if (algorithm == '8')
                {
                    v.set_window_name("Tim Sort");
                    v.set_algorithm(std::make_shared<TimSort>());
                }
                else if (algorithm == '9')
                {
                    v.set_window_name("Tree Sort");
                    v.set_algorithm(std::make_shared<TreeSort>());
                }
                complexity = '2';
            }
            if (complexity == '3')
            {
                if (!changed_size)
                {
                    v.set_array_size(200);
                }
                algorithm = make_decision
                (
                    "< Select algorithm >\n\n"
                    "[1] Bogo Sort - O((n + 1)!) (Default Array Size = 5)\n"
                    "[2] Comb Sort - O(n^2 / 2^p) (Default Array Size = 150)\n"
                    "[3] Cycle Sort on [1..n] array - O(n) (Default Array Size = 750)\n"
                    "[4] Pigeonhole Sort - O(n + Range) (Default Array Size = 300)\n"
                    "[5] Radix Sort - O(d * (n + b)) (Default Array Size = 750)\n"
                    "[6] Stooge Sort - O(n^2.7) (Default Array Size = 150)\n"
                    "[0] Go Back\n",
                    "0123456"
                );
                if (algorithm == '0')
                {
                    complexity = '-';
                    continue;
                }
                else if (algorithm == '1')
                {
                    if (!changed_size)
                    {
                        v.set_array_size(5);
                    }
                    v.set_window_name("Bogo Sort");
                    v.set_algorithm(std::make_shared<BogoSort>());
                }
                else if (algorithm == '2')
                {
                    if (!changed_size)
                    {
                        v.set_array_size(150);
                    }
                    v.set_window_name("Comb Sort");
                    v.set_algorithm(std::make_shared<CombSort>());
                }
                else if (algorithm == '3')
                {
                    if (!changed_size)
                    {
                        v.set_array_size(750);
                    }
                    v.set_window_name("Cycle Sort on [1..n] array");
                    v.set_algorithm(std::make_shared<FancyCycleSort>());
                }
                else if (algorithm == '4')
                {
                    if (!changed_size)
                    {
                        v.set_array_size(300);
                    }
                    v.set_window_name("Pigeonhole Sort");
                    v.set_algorithm(std::make_shared<PigeonholeSort>());
                }
                else if (algorithm == '5')
                {
                    if (!changed_size)
                    {
                        v.set_array_size(750);
                    }
                    v.set_window_name("Radix Sort");
                    v.set_algorithm(std::make_shared<RadixSort>());
                }
                else if (algorithm == '6')
                {
                    if (!changed_size)
                    {
                        v.set_array_size(150);
                    }
                    v.set_window_name("Stooge Sort");
                    v.set_algorithm(std::make_shared<StoogeSort>());
                }
                complexity = '3';
            }
            v.run(array_order);
        }
    }
}
