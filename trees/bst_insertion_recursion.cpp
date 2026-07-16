#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int getHeight(Node* root, int h) {
    if (root == nullptr) return h - 1;
    return max(getHeight(root->left, h + 1), getHeight(root->right, h + 1));
}

void levelOrder(Node* root) {
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    int lastLevel = 0;

    int height = getHeight(root, 0);

    while (!q.empty()) {
        auto top = q.front();
        q.pop();

        Node* node = top.first;
        int lvl = top.second;

        if (lvl > lastLevel) {
            cout << " ";
            lastLevel = lvl;
        }

        // all levels are printed
        if (lvl > height) break;

        // printing null node
        cout << (node->data == -1 ? "N" : to_string(node->data)) << " ";

        // null node has no children
        if (node->data == -1) continue;

        if (node->left == nullptr) q.push({new Node(-1), lvl + 1});
        else q.push({node->left, lvl + 1});

        if (node->right == nullptr) q.push({new Node(-1), lvl + 1});
        else q.push({node->right, lvl + 1});
    }
}

Node* insert(Node* root, int key) {
   
    // If the tree is empty, return a new node
    if (root == nullptr)
        return new Node(key);

    // Otherwise, recur down the tree
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    // Return the (unchanged) node pointer
    return root;
}

int main() {
    Node* root = nullptr;

    root = insert(root, 22);
    root = insert(root, 12);
    root = insert(root, 30);
    root = insert(root, 8);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 15);

    // print the level order 
    // traversal of the BST
    levelOrder(root);
}
