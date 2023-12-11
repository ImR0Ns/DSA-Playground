#pragma once
#include <algorithm>

struct AVLTree {
    //function helpers
private:
    int calculateHeight(AVLTree* root);

    int calculateBalance(AVLTree* node);

    void updateHeight(AVLTree*& node);

    void leftRotate(AVLTree*& root);

    void rightRotate(AVLTree*& root);

    AVLTree* findMin(AVLTree* node);
public:
    int data;
    AVLTree* left;
    AVLTree* right;
    int height;

    AVLTree(int data) : data(data), left(nullptr), right(nullptr), height(0) {}

    void insertNode(AVLTree*& node, int value);

    void rebalance(AVLTree*& root);

    void deleteNode(AVLTree*& root, int key);


};


/*
            INPUT EXAMPLES

    AVLTree* root = new AVLTree(5);
    root->insertNode(root, 3);
    root->insertNode(root, 4);
    root->insertNode(root, 8);
    root->insertNode(root, 2);

    root->deleteNode(root, 3);

    std::cout << "Root Data: " << root->data << std::endl;
    std::cout << "Left Data: " << root->left->data << std::endl;
    std::cout << "Right Data: " << root->right->data << std::endl;

    delete root;

*/