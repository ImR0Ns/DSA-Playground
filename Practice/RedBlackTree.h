#pragma once
#include <iostream>
#include <string>

struct RedBlackTree {
    int data;
    int color; // 1 red & 2 black
    RedBlackTree* left;
    RedBlackTree* right;
    RedBlackTree* root;

    explicit RedBlackTree(int data);

    void insert(int key);

    void inOrderTraversalWithColor();

private:
    void inOrderTraversalHelperWithColor(RedBlackTree* node);

    void leftRotate(RedBlackTree* x);

    void rightRotate(RedBlackTree* y);

    void insertFixup(RedBlackTree* newNode);
};
