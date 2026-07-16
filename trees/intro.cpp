// parent node : node that is immediate predecessor of another node.
// child node : node that is an immediate successor of another node.
// root node : the top most in a tree.
// leaf node : nodes that do not have any children.
// ancestor : any node on the path from the root to a given node.
// sibling : nodes that share the same parent.

//Types of Trees:
// Binary Tree:
// 1. Full Binary Tree : every node has either 0 or 2 children
// 2. Complete Binary Tree : all levels are fully filled except possibly the last,
// which is filled from left to right.
// 3. Balanced Binary Tree : height difference between left and right subtrees of 
// every node is minimal.

// Ternary Tree : each node can have atmost 3 children 

// N-ary Tree : 
// - each node can have any number of children
           
#include<iostream>
#include<vector>

using namespace std;

// node structure for tree
class Node{
    public:
    int data;
    vector<Node*> children;

    Node(int x){
        data = x;
    }
};

// function to add a child to a node
void addChild(Node* parent, Node* child){
    parent->children.push_back(child);
}

// function to print parents of each node
void printParents(Node* node, Node* parent){
    if (parent == nullptr)
        cout << node->data << " -> NULL" << endl;
    else
        cout << node->data << " -> " << parent->data << endl;
    
    for (auto child : node->children)
            printParents(child, node);
}

// function to print children of each node
void printChildren(Node* node){
    cout << node->data << "->";
    for (auto child : node->children)
        cout << child->data << " ";
    cout << endl;

    for (auto child : node->children)
        printChildren(child);
}

// function to print leaf nodes
void printLeafNodes(Node* node){
    if (node->children.empty()){
        cout << node->data << " ";
        return;
    }
    for (auto child : node->children)
        printLeafNodes(child);
}

// function to print degrees of each node
void printDegrees(Node* node, Node* parent){
    int degree = node->children.size();
    if (parent != nullptr)
        degree++;
    cout << node->data << "->" << degree << endl;

    for (auto child : node->children)
        printDegrees(child, node);
}

int main(){
    //creating nodes
    Node* root = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    //constructing tree
    addChild(root, n2);
    addChild(root, n3);
    addChild(root, n4);
    addChild(root, n5);

    cout << "Parents of each node: " << endl;
    printParents(root, nullptr);

    cout << "Children of each node: " << endl;
    printChildren(root);

    cout << "Leaf nodes: ";
    printLeafNodes(root);
    cout << endl;

    cout << "Degree of node: " << endl;
    printDegrees(root, nullptr);

    return 0;
    
}