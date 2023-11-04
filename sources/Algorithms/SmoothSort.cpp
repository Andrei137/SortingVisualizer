#include "../../includes/Algorithms/SmoothSort.hpp"

SmoothSort::SmoothSort() : Sort() {};

int SmoothSort::leonardo(int a_k) 
{
    if (a_k < 2) 
    {
        return 1;
    }
    std::vector<int> dp(a_k + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= a_k; ++i) 
    {
        dp[i] = dp[i - 1] + dp[i - 2] + 1;
    }
    return dp[a_k];
}

void SmoothSort::heapify(sf::RenderWindow& a_window, std::vector<int>& a_arr, int a_start, int a_end)
{
    int i{ a_start };
    int j{ 0 }, k{ 0 };
    while (k < a_end - a_start + 1)
    {
        if (k & 0xAAAAAAAA)
        {
            j += i;
            i >>= 1;
        }
        else
        {
            i += j;
            j >>= 1;
        }
        ++k;
    }
    while (i > 0)
    {
        j >>= 1;
        k = i + j;
        while (k < a_end)
        {
            if (a_arr[k] > a_arr[k - i])
            {
                break;
            }
            draw(a_window, a_arr, k, k - i, -1);
            std::swap(a_arr[k], a_arr[k - i]);
            k += i;
        }
        i = j;
    }
}

void SmoothSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    const int size{ (int)a_arr.size() };
    int p{ size - 1 };
    int q{ p };
    int r{ 0 };
    draw(a_window, a_arr, -1, -1, p);
    while (p > 0)
    {
        if ((r & 0x03) == 0)
        {
            heapify(a_window, a_arr, r, q);
        }
        if (leonardo(r) == p)
        {
            ++r;
        }
        else
        {
            --r;
            q -= leonardo(r);
            heapify(a_window, a_arr, r, q);
            q = r - 1;
            ++r;
        }
        std::swap(a_arr[0], a_arr[p]);
        --p;
    }
    for (int i = 0; i < size - 1; ++i)
    {
        int j{ i + 1 };
        draw(a_window, a_arr, -1, -1, i);
        while (j > 0 && a_arr[j] < a_arr[j - 1])
        {
            std::swap(a_arr[j], a_arr[j - 1]);
            --j;
        }
        draw(a_window, a_arr, -1, -1, i);
    }
}

