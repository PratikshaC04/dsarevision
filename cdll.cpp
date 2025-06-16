#include <iostream>
#include <string>
using namespace std;

class Recipe {
public:
    string name;
    Recipe* prev;
    Recipe* next;

    Recipe(string name) {
        this->name = name;
        prev = next = this;
    }
};

class RecipeList {
    Recipe* head;

public:
    RecipeList() {
        head = nullptr;
    }

    // Add recipe at end
    void insertEnd(string name) {
        Recipe* newNode = new Recipe(name);
        if (!head) {
            head = newNode;
            return;
        }

        Recipe* tail = head->prev;

        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    // Display forward
    void displayForward() {
        if (!head) {
            cout << "No recipes found.\n";
            return;
        }
        Recipe* temp = head;
        cout << "\nRecipes (Forward):\n";
        do {
            cout << "- " << temp->name << endl;
            temp = temp->next;
        } while (temp != head);
    }

    // Display backward
    void displayBackward() {
        if (!head) {
            cout << "No recipes found.\n";
            return;
        }
        Recipe* temp = head->prev;
        Recipe* start = temp;
        cout << "\nRecipes (Backward):\n";
        do {
            cout << "- " << temp->name << endl;
            temp = temp->prev;
        } while (temp != start);
    }

    // Count number of recipes
    int countNodes() {
        if (!head) return 0;
        int count = 0;
        Recipe* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }

    // Insert M recipes after position N
    void insertAfterPosition(int n, int m) {
        int total = countNodes();
        if (!head || n < 0 || n > total) {
            cout << "Invalid position.\n";
            return;
        }

        Recipe* temp = head;
        for (int i = 1; i < n && temp->next != head; i++)
            temp = temp->next;

        for (int i = 0; i < m; i++) {
            string newName;
            cout << "Enter name of new recipe " << i + 1 << ": ";
            cin.ignore();
            getline(cin, newName);

            Recipe* newNode = new Recipe(newName);
            Recipe* nextNode = temp->next;

            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = nextNode;
            nextNode->prev = newNode;

            temp = newNode; // for next insertion
        }
    }
};

int main() {
    RecipeList rl;
    int choice;

    do {
        cout << "\n--- Recipe Menu ---\n";
        cout << "1. Add Recipe\n";
        cout << "2. Display Forward\n";
        cout << "3. Display Backward\n";
        cout << "4. Insert M Recipes After Position N\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // flush newline

        switch (choice) {
            case 1: {
                string name;
                cout << "Enter recipe name: ";
                getline(cin, name);
                rl.insertEnd(name);
                break;
            }
            case 2:
                rl.displayForward();
                break;
            case 3:
                rl.displayBackward();
                break;
            case 4: {
                int n, m;
                cout << "Enter position N after which to insert: ";
                cin >> n;
                cout << "Enter number of recipes M to insert: ";
                cin >> m;
                rl.insertAfterPosition(n, m);
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
