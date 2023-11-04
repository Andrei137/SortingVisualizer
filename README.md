# Sorting Visualizer

## About
A simple sorting visualizer made using C++ and SFML. The project includes 24 algorithms, grouped by complexity. The user can choose the size of the array, the initial order of the array and the algorithm to be used. The project also includes a timer, which appears afer the algorithm finishes. Keep in mind that the timer shows how long it took to display the process, not how long it took to sort the array.

## Algorithms
### O(n^2)
- [x] Bubble Sort
- [x] Cocktail Sort
- [x] Cycle Sort
- [x] Gnome Sort
- [x] Insertion Sort
- [x] Odd-Even Sort
- [x] Pancake Sort
- [x] Selection Sort
- [x] Selection Sort (Exchange Variation)
### O(n * log_n)
- [x] Heap Sort
- [x] Intro Sort
- [x] Merge Sort
- [x] Quick Sort (Lomuto partition scheme)
- [x] Quick Sort (Hoare partition scheme)
- [x] Shell Sort
- [x] Smooth Sort
- [x] Tim Sort
- [x] Tree Sort
### Other complexities
- [x] Bogo Sort - O((n + 1)!)
- [x] Comb Sort - O(n^2 / 2^p)
- [x] Cycle Sort on [1..n] array - O(n)
- [x] Pigeonhole Sort - O(n + Range)
- [x] Radix Sort - O(d * (n + b))
- [x] Stooge Sort - O(n^2.7)

## Options
### Array Size
- [x] Default size for every algorithm
- [x] Custom size given by user
### Array Initial Order
- [x] Random Shuffle (default)
- [x] Partially Sorted
- [x] Nearly Sorted
- [x] Decreasing Order
- [x] Increasing Order


## Credits
- [SFML](https://www.sfml-dev.org/)
- [Rlutil](https://github.com/tapio/rlutil)