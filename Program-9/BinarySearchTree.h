#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <typename T>
class BinarySearchTree;

template <typename T>
class BSTNode
{
private:
    BSTNode<T> *left;
    BSTNode<T> *right;
    T data;

public:
    BSTNode(const T& value, BSTNode<T> *l, BSTNode<T> *r);
    friend class BinarySearchTree<T>;
}; // BSTNode


template <typename T>
class BinarySearchTree
{
private:
    BSTNode<T> *root;

    const BSTNode<T> * findMin(const BSTNode<T> *t) const;
    void makeEmpty(const BSTNode<T> *t) const;

    void insert(BSTNode<T> *t, const T &value);
    void removeNode(BSTNode<T> * &t, const T &value);
    void remove(BSTNode<T> * &t, const T &value);
    const BSTNode<T> * find(const BSTNode<T> *t, const T&value) const;
    void inOrder( const BSTNode<T> *t) const;
    void postOrder(const BSTNode<T> *t) const;

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(const T & value);
    void remove(const T & value);
    void find(const T& value) const;
    void inOrder() const;
    void postOrder()const;

}; // BinarySearchTree

#include "BinarySearchTree.cpp"

#endif
