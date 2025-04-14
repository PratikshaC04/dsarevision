#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0) return false;
    int original = x, reversed = 0;
    while (x != 0) {
        int digit = x % 10;
        if (reversed > (INT32_MAX - digit) / 10) return false; // overflow check
        reversed = reversed * 10 + digit;
        x /= 10;
    }
    return original == reversed;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (isPalindrome(num))
        cout << num << " is a palindrome.\n";
    else
        cout << num << " is not a palindrome.\n";
    return 0;
}

