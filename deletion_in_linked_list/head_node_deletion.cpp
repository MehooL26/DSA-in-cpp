// C++ program to show how to delete a head node from
// the linked list
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to delete the head node
void deleteHead(Node *&head) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    // Store current head in a temporary variable
    Node *temp = head;

    // Move head to the next node
    head = head->next;

    // Delete the old head node
    delete temp;
}

int main() {

    // Create a simple linked list: 3 -> 12 -> 15 -> 18
    Node *head = new Node(3);
    head->next = new Node(12);
    head->next->next = new Node(15);
  	head->next->next->next = new Node(18);
  
    cout << "Original List: ";
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    deleteHead(head); // Deleting the head node

    cout << "List after deleting head: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}