#include <iostream>
#include <algorithm>


struct RedBlackTree {
    int data;
    int color; // 1 red & 2 black
    RedBlackTree* left;
    RedBlackTree* right;


    explicit RedBlackTree(int data) : data(data), color(0), left(nullptr), right(nullptr) {};

    void insert(RedBlackTree* node) {
    }
};

int main() {

    RedBlackTree rbTree(10);
    rbTree.insert(new RedBlackTree(5));
    rbTree.insert(new RedBlackTree(15));

    return 0;
}
