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

Node* getNode() {
    int n;
    cout << "Enter the data: ";
    cin >> n;
    Node* t = new Node(n);
    return t;
}

Node* insert_rear(Node* first) {
    Node* t = getNode();
    if (first == nullptr)
        return t;
    Node* temp = first;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = t;
    return first;
}

void display(Node* first) {
    if (first == nullptr) {
        cout << "List empty\n";
        return;
    }
    Node* c = first;
    while (c != nullptr) {
        cout << c->data << " ";
        c = c->next;
    }
    cout << endl;
}

Node* merge_list(Node* first1, Node* first2) {
    if (first1 == nullptr)
        return first2;
    if (first2 == nullptr)
        return first1;

    Node* c = first1;
    while (c->next != nullptr)
        c = c->next;

    c->next = first2;

    cout << "After merging\n";
    display(first1);
    return first1;
}

int main() {
    Node* first1 = nullptr;
    Node* first2 = nullptr;
    Node* merged = nullptr;
    int choice;

    while (true) {
        cout << "\nEnter:\n 1 - Insert rear\n 2 - Display\n 3 - Merge lists\n 4 - Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the element in list 1\n";
            first1 = insert_rear(first1);
            cout << "Enter the element in list 2\n";
            first2 = insert_rear(first2);
            break;
        case 2:
            cout << "Elements of first list:\n";
            display(first1);
            cout << "Elements of second list:\n";
            display(first2);
            break;
        case 3:
            merged = merge_list(first1, first2);
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
