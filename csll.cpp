#include <iostream>
#include <cstring>
using namespace std;

class Node {
public:
    char project_name[20];
    int marks;
    Node* next;

    Node(const char* pname, int m) {
        strcpy(project_name, pname);
        marks = m;
        next = this;
    }
};

class CircularList {
private:
    Node* first;

public:
    CircularList() {
        first = nullptr;
    }

    void insert_rear() {
        char name[20];
        int m;
        cout << "Enter project name and marks scored: ";
        cin >> name >> m;

        Node* t = new Node(name, m);
        if (!first) {
            first = t;
            return;
        }

        Node* c = first;
        while (c->next != first)
            c = c->next;

        c->next = t;
        t->next = first;
    }

    void display() {
        if (!first) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = first;
        cout << "\n--- Participant List ---\n";
        do {
            cout << "Project name: " << temp->project_name << "\nMarks: " << temp->marks << "\n";
            temp = temp->next;
        } while (temp != first);
    }

    void sort_by_marks() {
        if (!first || first->next == first)
            return;

        bool swapped;
        Node *temp1, *temp2 = nullptr;

        do {
            swapped = false;
            temp1 = first;

            while (temp1->next != temp2 && temp1->next != first) {
                if (temp1->marks > temp1->next->marks) {
                    // Swap project name and marks
                    swap(temp1->marks, temp1->next->marks);
                    char temp_name[20];
                    strcpy(temp_name, temp1->project_name);
                    strcpy(temp1->project_name, temp1->next->project_name);
                    strcpy(temp1->next->project_name, temp_name);
                    swapped = true;
                }
                temp1 = temp1->next;
            }
            temp2 = temp1;
        } while (swapped);
    }

    void delete_front() {
        if (!first) {
            cout << "List is empty\n";
            return;
        }

        if (first->next == first) {
            cout << first->marks << " marks will be deleted\n";
            delete first;
            first = nullptr;
            return;
        }

        Node* last = first;
        while (last->next != first)
            last = last->next;

        Node* temp = first;
        first = first->next;
        last->next = first;
        cout << temp->marks << " marks will be deleted\n";
        delete temp;
    }

    ~CircularList() {
        while (first)
            delete_front();
    }
};

int main() {
    CircularList cl;
    int choice;

    do {
        cout << "\n1. Insert Participant\n2. Display All\n3. Delete Lowest Scorer\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cl.insert_rear();
                break;
            case 2:
                cl.display();
                break;
            case 3:
                cl.sort_by_marks();
                cl.delete_front();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}
