#include <iostream>
#include <unordered_set> // Not strictly needed for this method, but good to include if experimenting

class Solution {
public:
    // Helper function to calculate the sum of squares of digits
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int digit = n % 10; // Get the last digit
            totalSum += digit * digit; // Add its square to the sum
            n /= 10; // Remove the last digit
        }
        return totalSum;
    }

    bool isHappy(int n) {
        int slow = n; // Tortoise pointer, moves one step at a time
        int fast = n; // Hare pointer, moves two steps at a time

        // Keep moving until slow and fast pointers meet
        // This loop will eventually terminate because either:
        // 1. Both pointers reach 1.
        // 2. Both pointers meet in a cycle that does not include 1.
        do {
            slow = getNext(slow);         // Slow moves one step
            fast = getNext(getNext(fast)); // Fast moves two steps
        } while (slow != fast);

        // If they meet at 1, the number is happy.
        // Otherwise, they met in a cycle that does not include 1, so it's not happy.
        return slow == 1;
    }
};

// Example Usage (for testing locally)
/*
int main() {
    Solution sol;
    std::cout << "Is 19 a happy number? " << (sol.isHappy(19) ? "True" : "False") << std::endl; // Expected: True
    std::cout << "Is 2 a happy number? " << (sol.isHappy(2) ? "True" : "False") << std::endl;   // Expected: False
    std::cout << "Is 7 a happy number? " << (sol.isHappy(7) ? "True" : "False") << std::endl;   // Expected: True
    std::cout << "Is 1 a happy number? " << (sol.isHappy(1) ? "True" : "False") << std::endl;   // Expected: True
    std::cout << "Is 10 a happy number? " << (sol.isHappy(10) ? "True" : "False") << std::endl;  // Expected: True
    return 0;
}
*/