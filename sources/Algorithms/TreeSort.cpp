#include "../../includes/Algorithms/TreeSort.hpp"

TreeSort::TreeSort() : Sort() {};

struct TreeSort::Node
{
    int data;
    Node* left;
    Node* right;
};

TreeSort::Node* TreeSort::new_node(int a_data)
{
    Node* node{ new Node };
    node->data = a_data;
    node->left = node->right = nullptr;
    return node;
}

TreeSort::Node* TreeSort::insert(Node* a_node, int a_data)
{
    if (a_node == nullptr)
    {
        return new_node(a_data);
    }
    if (a_data < a_node->data)
    {
        a_node->left = insert(a_node->left, a_data);
    }
    else if (a_data > a_node->data)
    {
        a_node->right = insert(a_node->right, a_data);
    }
    return a_node;
}

void TreeSort::store_sorted(sf::RenderWindow& a_window, Node* a_node, std::vector<int>& a_arr, int& a_i)
{
    if (a_node != nullptr)
    {
        store_sorted(a_window, a_node->left, a_arr, a_i);
        a_arr[a_i++] = a_node->data;
        draw(a_window, a_arr, -1, -1, a_i - 1);
        store_sorted(a_window, a_node->right, a_arr, a_i);
    }
}

void TreeSort::sort(sf::RenderWindow& a_window, std::vector<int>& a_arr)
{
    Node* root{ nullptr };
    for (int i : a_arr)
    {
        root = insert(root, i);
    }
    int i{ 0 };
    store_sorted(a_window, root, a_arr, i);
}
