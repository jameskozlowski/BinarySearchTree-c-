#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <cstddef>
#include <stdexcept>

/**
* The BinarySearchTree class implements an binary search tree(BST)
* 
* This version of a BST is a simple implementation for the purpose of fast binary search
* No logic is added to insure a balanced tree and there is no way to rearrange/delete the tree
*
* All objects add to the tree must Extend Comparable and be unique, any 2 objects that compare equal
* cannot both exist in the tree. This may require you to implement some sort of hashing to the compareTo.
*
* @author  James Kozlowski
* @version March 30, 2017
*/
template <class T> class BinarySearchTree
{
    private:
        /**
        * object stored in this tree node.
        */
        T value;

        /**
        * Left side child tree
        */
        BinarySearchTree<T> *left;

        /**
        * Right side child tree
        */
        BinarySearchTree<T> *right;

    public:
        /**
        * This is the constructor that creats the binary tree root
        * @param valueIn the object to store in this tree node
        * @return Nothing.
        */
        BinarySearchTree(T valueIn);

        /**
        * Deconstructor
        * @return Nothing.
        */
        ~BinarySearchTree();

        /**
        * Adds a object to the correct place in the tree
        *
        * No logic is added to insure a balanced tree  
        * Any 2 objects that compare equal cannot both exist in the tree. 
        * This may require you to implement some sort of hashing to the compareTo.
        *
        * @param valueIn the value to store in this tree node
        * @return Nothing.
        * @throws std::invalid_argument if the object is allready in the tree
        */
        void add(T valueIn);

        /**
        * Finds the given object in the Binary Tree
        * @param valueIn the object to find
        * @return the object if found, or null if the object was not found
        */
        T find(T valueIn);
};


/**
* This is the constructor that creats the binary tree root
* @param valueIn the object to store in this tree node
* @return Nothing.
*/
template <class T> BinarySearchTree<T>::BinarySearchTree(T valueIn)
{
    left  = NULL;
    right = NULL;
    value = valueIn;
}

/**
* Deconstructor
* @return Nothing.
*/
template <class T> BinarySearchTree<T>::~BinarySearchTree()
{
    if (left != NULL)
        delete(left);
    if (right != NULL)
        delete(right);
}

/**
* Adds a object to the correct place in the tree
*
* No logic is added to insure a balanced tree  
* Any 2 objects that compare equal cannot both exist in the tree. 
* This may require you to implement some sort of hashing to the compareTo.
*
* @param valueIn the value to store in this tree node
* @return Nothing.
* @throws std::invalid_argument if the object is allready in the tree
*/
template <class T> void BinarySearchTree<T>::add(T valueIn)
{
    if (valueIn < value)
    {
        if (left == NULL)
            left = new BinarySearchTree<T>(valueIn);
        else
            left->add(valueIn);
    }
    else if (valueIn > value)
    {
        if (right == NULL)
            right = new BinarySearchTree<T>(valueIn);
        else
            right->add(valueIn);
    }
    else
        throw std::invalid_argument("Object is allready in the Binary Search Tree");
}

/**
* Finds the given object in the Binary Tree
* @param valueIn the object to find
* @return the object if found, or null if the object was not found
*/
template <class T> T BinarySearchTree<T>::find(T valueIn)
{
    if (value == valueIn)
        return value;
    else if (valueIn < value && left != NULL)
        left->find(valueIn);
    else if (valueIn > value && right != NULL)
        right->find(valueIn);
    else
        return 0;
}

#endif 