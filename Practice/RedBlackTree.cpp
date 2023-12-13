#include "RedBlackTree.h"

RedBlackTree::RedBlackTree(int data) : data(data), color(2), left(nullptr), right(nullptr), root(this) {}

void RedBlackTree::insert(int key) {
    RedBlackTree* newNode = new RedBlackTree(key);
    RedBlackTree* y = nullptr;
    RedBlackTree* x = root;

    while (x != nullptr) {
        y = x;
        if (newNode->data < x->data) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }

    newNode->root = y;
    if (y == nullptr) {
        root = newNode;
    }
    else if (newNode->data < y->data) {
        y->left = newNode;
    }
    else {
        y->right = newNode;
    }

    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->color = 1; // Red

    // Fix the Red-Black Tree properties after insertion
    insertFixup(newNode);
}

void RedBlackTree::inOrderTraversalWithColor() {
    if (root != nullptr) {
        inOrderTraversalHelperWithColor(root);
    }
}

void RedBlackTree::inOrderTraversalHelperWithColor(RedBlackTree* node) {
    if (node != nullptr) {
        inOrderTraversalHelperWithColor(node->left);

        std::string colorString = (node->color == 1) ? "Red" : "Black";
        std::cout << node->data << " (" << colorString << ") ";

        inOrderTraversalHelperWithColor(node->right);
    }
}

void RedBlackTree::leftRotate(RedBlackTree* x) {
    RedBlackTree* y = x->right;
    x->right = y->left;

    if (y->left != nullptr) {
        y->left->root = x;
    }

    y->root = x->root;
    if (x->root == nullptr) {
        root = y;
    }
    else if (x == x->root->left) {
        x->root->left = y;
    }
    else {
        x->root->right = y;
    }

    y->left = x;
    x->root = y;
}

void RedBlackTree::rightRotate(RedBlackTree* y) {
    RedBlackTree* x = y->left;
    y->left = x->right;

    if (x->right != nullptr) {
        x->right->root = y;
    }

    x->root = y->root;
    if (y->root == nullptr) {
        root = x;
    }
    else if (y == y->root->left) {
        y->root->left = x;
    }
    else {
        y->root->right = x;
    }

    x->right = y;
    y->root = x;
}

void RedBlackTree::insertFixup(RedBlackTree* newNode) {
    while (newNode != root && newNode->root->color == 1) {
        if (newNode->root == newNode->root->root->left) {
            RedBlackTree* y = newNode->root->root->right;
            if (y != nullptr && y->color == 1) {
                newNode->root->color = 2;
                y->color = 2;
                newNode->root->root->color = 1;
                newNode = newNode->root->root;
            }
            else {
                if (newNode == newNode->root->right) {
                    newNode = newNode->root;
                    leftRotate(newNode);
                }
                newNode->root->color = 2;
                newNode->root->root->color = 1;
                rightRotate(newNode->root->root);
            }
        }
        else {
            RedBlackTree* y = newNode->root->root->left;
            if (y != nullptr && y->color == 1) {
                newNode->root->color = 2;
                y->color = 2;
                newNode->root->root->color = 1;
                newNode = newNode->root->root;
            }
            else {
                if (newNode == newNode->root->left) {
                    newNode = newNode->root;
                    rightRotate(newNode);
                }
                newNode->root->color = 2;
                newNode->root->root->color = 1;
                leftRotate(newNode->root->root);
            }
        }
    }
    root->color = 2;
}
