#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* llink;
    Node* rlink;

    Node(int val) {
        data = val;
        llink = rlink = nullptr;
    }
};

// Insert at rear
Node* insert_rear(Node* first, int value) {
    Node* t = new Node(value);

    if (first == nullptr)
        return t;

    Node* temp = first;
    while (temp->rlink != nullptr)
        temp = temp->rlink;

    temp->rlink = t;
    t->llink = temp;
    return first;
}

// Display list
void display(Node* first) {
    if (first == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = first;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->rlink;
    }
    cout << endl;
}

// Delete all nodes whose data < right neighbor's data
Node* delete_greater_right(Node* first) {
    if (first == nullptr || first->rlink == nullptr)
        return first;

    Node* t = first;

    while (t != nullptr && t->rlink != nullptr) {
        if (t->data < t->rlink->data) {
            cout << t->data << " will be deleted" << endl;
            Node* to_delete = t;

            if (to_delete == first) {
                first = to_delete->rlink;
                if (first)
                    first->llink = nullptr;
                t = first;
            } else {
                Node* prev = to_delete->llink;
                Node* next = to_delete->rlink;
                prev->rlink = next;
                if (next)
                    next->llink = prev;
                t = next;
            }

            delete to_delete;
        } else {
            t = t->rlink;
        }
    }

    return first;
}

int main() {
    Node* first = nullptr;
    int choice, value;

    while (true) {
        cout << "\n1 - Insert rear\n2 - Display\n3 - Delete nodes with greater node on right\n4 - Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                first = insert_rear(first, value);
                break;
            case 2:
                cout << "List elements: ";
                display(first);
                break;
            case 3:
                first = delete_greater_right(first);
                cout << "Updated list: ";
                display(first);
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
