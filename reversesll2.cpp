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

// Function to get a new node from user input
Node* getNode() {
    int n;
    cout << "Enter the data: ";
    cin >> n;
    Node* t = new Node(n);
    return t;
}

// Insert at rear
Node* insertRear(Node* first) {
    Node* t = getNode();
    if (first == nullptr)
        return t;

    Node* temp = first;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = t;
    return first;
}

// Display the linked list
void display(Node* first) {
    if (first == nullptr) {
        cout << "List empty" << endl;
        return;
    }

    Node* c = first;
    while (c != nullptr) {
        cout << c->data << " ";
        c = c->next;
    }
    cout << endl;
}

// Reverse the linked list
Node* reverseList(Node* first) {
    Node* prev = nullptr;
    Node* curr = first;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev; // new head of reversed list
}

int main() {
    Node* first = nullptr;
    int choice;

    while (true) {
        cout << "\nEnter:\n 1 - Insert rear\n 2 - Display\n 3 - Reverse list\n 4 - Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the elements in list:" << endl;
            first = insertRear(first);
            break;
        case 2:
            cout << "Elements of list:" << endl;
            display(first);
            break;
        case 3:
            first = reverseList(first);
            cout << "Reversed list:" << endl;
            display(first);
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
