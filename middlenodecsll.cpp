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

// Function to create a new node with user input
Node* getNode() {
    int n;
    cout << "Enter the data: ";
    cin >> n;
    Node* t = new Node(n);
    return t;
}

// Insert at rear for circular singly linked list
Node* insertRear(Node* first) {
    Node* t = getNode();
    if (first == nullptr) {
        t->next = t;  // make circular
        return t;
    }

    Node* temp = first;
    while (temp->next != first)
        temp = temp->next;

    temp->next = t;
    t->next = first;
    return first;
}

// Display the circular list
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

// Find middle node (non-optimized method)
Node* middleNode(Node* first) {
    if (first == nullptr)
        return nullptr;

    int count = 1;
    Node* t = first;

    // Count total nodes
    while (t->next != first) {
        count++;
        t = t->next;
    }

    // Traverse to middle
    int mid = count / 2;
    t = first;
    for (int i = 0; i < mid; i++) {
        t = t->next;
    }

    return t;
}

int main() {
    Node* first = nullptr;
    int choice;

    while (true) {
        cout << "\nEnter:\n 1 - Insert rear\n 2 - Display\n 3 - Middle node\n 4 - Exit\n";
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
        case 3: {
            Node* mid = middleNode(first);
            if (mid)
                cout << "The middle node is " << mid->data << endl;
            else
                cout << "List is empty.\n";
            break;
        }
        case 4:
            exit(0);
        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
