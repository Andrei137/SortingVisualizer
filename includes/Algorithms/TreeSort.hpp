#pragma once

#include "Sort.hpp"

class TreeSort : public Sort
{
    struct Node;
    struct Node* new_node(int);
    Node* insert(Node*, int);
    void store_sorted(sf::RenderWindow&, Node*, std::vector<int>&, int&);
public:
    TreeSort();
    void sort(sf::RenderWindow&, std::vector<int>&) override;
};
