#include <iostream>
#include <climits>
using namespace std;

int second_largest(int n, int a[]); // Function declaration

int main() {
    int n;
    cout << "Enter the number of elements in array: ";
    cin >> n;

    int a[n];
    cout << "Enter the elements in array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int f = second_largest(n, a);
    if (f == INT_MIN) {
        cout << "There is no second largest element (all elements might be same)." << endl;
    } else {
        cout << "The second largest element is: " << f << endl;
    }

    return 0;
}

int second_largest(int n, int a[]) {
    int largest = INT_MIN;
    int second = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (a[i] > largest) {
            second = largest;
            largest = a[i];
        } else if (a[i] > second && a[i] != largest) {
            second = a[i];
        }
    }

    return second;
}
