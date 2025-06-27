#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to create a new node from user input
Node* getNode() {
    int n;
    cout << "Enter the data: ";
    cin >> n;
    Node* t = new Node(n);
    return t;
}

// Insert node at the rear of the circular linked list
Node* insertRear(Node* first) {
    Node* t = getNode();
    if (first == nullptr) {
        t->next = t; // circular link to self
        return t;
    }

    Node* temp = first;
    while (temp->next != first)
        temp = temp->next;

    temp->next = t;
    t->next = first;
    return first;
}

// Display the circular linked list
void display(Node* first) {
    if (first == nullptr) {
        cout << "List empty\n";
        return;
    }

    Node* c = first;
    do {
        cout << c->data << " ";
        c = c->next;
    } while (c != first);
    cout << endl;
}

// Delete first occurrence of a key
Node* deleteFirstOccurrence(Node* first, int key) {
    if (first == nullptr) {
        cout << "List is empty\n";
        return nullptr;
    }

    cout << "Enter the key to be checked: ";
    cin >> key;

    Node* curr = first;
    Node* prev = nullptr;

    // Special case: only one node
    if (curr->next == first && curr->data == key) {
        delete curr;
        return nullptr;
    }

    // Special case: head is to be deleted
    if (curr->data == key) {
        // Find last node to fix circular link
        Node* last = first;
        while (last->next != first)
            last = last->next;

        last->next = curr->next;
        Node* temp = curr;
        first = curr->next;
        cout << temp->data << " to be deleted\n";
        delete temp;
        return first;
    }

    // General case
    prev = curr;
    curr = curr->next;

    while (curr != first && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == first) {
        cout << "Key not found\n";
        return first;
    }

    prev->next = curr->next;
    cout << curr->data << " to be deleted\n";
    delete curr;
    return first;
}

int main() {
    Node* first = nullptr;
    int choice, key;

    while (true) {
        cout << "\nEnter:\n1 - Insert rear\n2 - Display\n3 - Delete first occurrence\n4 - Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element in list:\n";
                first = insertRear(first);
                break;
            case 2:
                cout << "Elements of list:\n";
                display(first);
                break;
            case 3:
                first = deleteFirstOccurrence(first, key);
                display(first);
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}
