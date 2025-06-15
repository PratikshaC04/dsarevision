#include <iostream>
#include <string>
using namespace std;

class Satellite {
public:
    int launchYear;
    string status;
    Satellite* next;

    Satellite(int year, string stat) {
        launchYear = year;
        status = stat;
        next = nullptr;
    }
};

class SatelliteList {
private:
    Satellite* head;

public:
    SatelliteList() {
        head = nullptr;
    }

    void insertRear(int year, const string& status) {
        Satellite* newSat = new Satellite(year, status);
        if (head == nullptr) {
            head = newSat;
        } else {
            Satellite* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newSat;
        }
    }

    void deleteNonFunctional() {
        Satellite* curr = head;
        Satellite* prev = nullptr;

        while (curr != nullptr) {
            if (curr->status == "non func" || curr->status == "non-functional" || curr->status == "nonfunc") {
                Satellite* toDelete = curr;
                if (curr == head) {
                    head = curr->next;
                    curr = head;
                } else {
                    prev->next = curr->next;
                    curr = curr->next;
                }
                delete toDelete;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    void display2023and2024() const {
        Satellite* temp = head;
        bool found = false;
        cout << "\nSatellites launched in 2023 or 2024:\n";
        while (temp != nullptr) {
            if (temp->launchYear == 2023 || temp->launchYear == 2024) {
                cout << "Year: " << temp->launchYear << ", Status: " << temp->status << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "No satellites launched in 2023 or 2024 found.\n";
        }
    }

    void displayAll() const {
        Satellite* temp = head;
        if (temp == nullptr) {
            cout << "Satellite list is empty.\n";
            return;
        }
        cout << "\nAll satellites:\n";
        while (temp != nullptr) {
            cout << "Year: " << temp->launchYear << ", Status: " << temp->status << endl;
            temp = temp->next;
        }
    }

    ~SatelliteList() {
        Satellite* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main menu-driven function
int main() {
    SatelliteList sList;
    int choice;
    int year;
    string status;

    do {
        cout << "\n===== Satellite Management System =====\n";
        cout << "1. Insert Satellite\n";
        cout << "2. Delete Non-Functional Satellites\n";
        cout << "3. Display Satellites Launched in 2023 or 2024\n";
        cout << "4. Display All Satellites\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter launch year: ";
            cin >> year;
            cout << "Enter status (functional / non func): ";
            cin.ignore(); // Clear newline
            getline(cin, status);
            sList.insertRear(year, status);
            break;

        case 2:
            sList.deleteNonFunctional();
            cout << "Non-functional satellites removed.\n";
            break;

        case 3:
            sList.display2023and2024();
            break;

        case 4:
            sList.displayAll();
            break;

        case 5:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
