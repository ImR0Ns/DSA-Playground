#include "AVLTree.h"

int AVLTree::calculateHeight(AVLTree* root) {
    return (root != nullptr) ? root->height : -1;
}

int AVLTree::calculateBalance(AVLTree* node) {
    return (node != nullptr) ? calculateHeight(node->left) - calculateHeight(node->right) : 0;
}

void AVLTree::updateHeight(AVLTree*& node) {
    if (node != nullptr) {
        node->height = 1 + std::max(calculateHeight(node->left), calculateHeight(node->right));
    }
}

void AVLTree::leftRotate(AVLTree*& root) {
    AVLTree* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;

    updateHeight(root);
    updateHeight(newRoot);

    root = newRoot;
}

void AVLTree::rightRotate(AVLTree*& root) {
    AVLTree* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;

    updateHeight(root);
    updateHeight(newRoot);

    root = newRoot;
}

void AVLTree::insertNode(AVLTree*& node, int value) {
    if (node == nullptr) {
        node = new AVLTree(value);
    }
    else if (value < node->data) {
        insertNode(node->left, value);
    }
    else if (value > node->data) {
        insertNode(node->right, value);
    }

    updateHeight(node);
    rebalance(node);
}

void AVLTree::rebalance(AVLTree*& root) {
    int balance = calculateBalance(root);

    if (balance > 1) {
        if (calculateBalance(root->left) >= 0) {
            rightRotate(root);
        }
        else {
            leftRotate(root->left);
            rightRotate(root);
        }
    }
    else if (balance < -1) {
        if (calculateBalance(root->right) <= 0) {
            leftRotate(root);
        }
        else {
            rightRotate(root->right);
            leftRotate(root);
        }
    }
}

void AVLTree::deleteNode(AVLTree*& root, int key) {
    if (root == nullptr) {
        return; // Key not found
    }

    if (key < root->data) {
        deleteNode(root->left, key);
    }
    else if (key > root->data) {
        deleteNode(root->right, key);
    }
    else {

        if (root->left == nullptr || root->right == nullptr) {
            AVLTree* temp = (root->left != nullptr) ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else {
                *root = *temp;
            }

            delete temp;
        }
        else {
            AVLTree* temp = findMin(root->right);
            root->data = temp->data;
            deleteNode(root->right, temp->data);
        }
    }

    // Update height and rebalance
    updateHeight(root);
    rebalance(root);
}

AVLTree* AVLTree::findMin(AVLTree* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}