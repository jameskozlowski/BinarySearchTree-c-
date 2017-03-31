#include "BinarySearchTree.hpp"
#include <iostream>

int main(int argc, char **args)
{
    BinarySearchTree<int> *root = new BinarySearchTree<int>(3);
    root->add(4);
    root->add(6);
    root->add(5);

    std::cout << root->find(30);

    delete(root);
    return 1;
}