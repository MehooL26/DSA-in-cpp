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

    Node(int item) {
        data = item;
        left = right = nullptr;
    }
};

int getHeight(Node* root, int h) {
    if (root == nullptr) return h - 1;
    return max(getHeight(root->left, h + 1), getHeight(root->right, h + 1));
}

void levelOrder(Node* root) {
    queue<pair<Node*, int>> queue;
    queue.push({root, 0});

    int lastLevel = 0;
    int height = getHeight(root, 0);
    
    while (!queue.empty()) {
        auto top = queue.front();
        queue.pop();

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

        if (node->left == nullptr) queue.push({new Node(-1), lvl + 1});
        else queue.push({node->left, lvl + 1});

        if (node->right == nullptr) queue.push({new Node(-1), lvl + 1});
        else queue.push({node->right, lvl + 1});
    }
}

Node* insert(Node* root, int key) {
    Node* temp = new Node(key);

    // If tree is empty
    if (root == nullptr) {
        return temp;
    }

    // Find the node who is going to 
    // have the new node as its child
    Node* curr = root;
    while (curr != nullptr) {
        if (curr->data > key && curr->left != nullptr) {
            curr = curr->left;
        } else if (curr->data < key && curr->right != nullptr) {
            curr = curr->right;
        } else break;
    }

    // If key is smaller, make it left 
    // child, else right child
    if (curr->data > key) {
        curr->left = temp;
    } else {
        curr->right = temp;
    }
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

    // print the level order traversal of the BST
    levelOrder(root);
}
