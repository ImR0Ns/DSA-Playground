#include <iostream>
#include <algorithm>

struct AVLTree {
//function helpers
private:
    int calculateHeight(AVLTree* root) {
        return (root != nullptr) ? root->height : -1;
    }

    int calculateBalance(AVLTree* node) {
        return (node != nullptr) ? calculateHeight(node->left) - calculateHeight(node->right) : 0;
    }

    void updateHeight(AVLTree*& node) {
        if (node != nullptr) {
            node->height = 1 + std::max(calculateHeight(node->left), calculateHeight(node->right));
        }
    }

    void leftRotate(AVLTree*& root) {
        AVLTree* newRoot = root->right;
        root->right = newRoot->left;
        newRoot->left = root;

        updateHeight(root);
        updateHeight(newRoot);

        root = newRoot;
    }

    void rightRotate(AVLTree*& root) {
        AVLTree* newRoot = root->left;
        root->left = newRoot->right;
        newRoot->right = root;

        updateHeight(root);
        updateHeight(newRoot);

        root = newRoot;
    }
public:
    int data;
    AVLTree* left;
    AVLTree* right;
    int height;

    AVLTree(int data) : data(data), left(nullptr), right(nullptr), height(0) {}

    void insertNode(AVLTree*& node, int value) {
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

    void rebalance(AVLTree*& root) {
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
};

int main() {
    AVLTree* root = nullptr;
    root->insertNode(root, 10);
    root->insertNode(root, 8);
    root->insertNode(root, 6);
    root->insertNode(root, 4);

    std::cout << "Root Data: " << root->data << std::endl;
    std::cout << "Left Data: " << root->left->data << std::endl;
    std::cout << "Right Data: " << root->right->data << std::endl;

    delete root;

    return 0;
}
