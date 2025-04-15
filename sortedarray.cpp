#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& arr) {
        int n = arr.size();
        int countBreaks = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > arr[(i + 1) % n]) { // Compare current with next (circular)
                countBreaks++;
            }
            if (countBreaks > 1) {
                return false; // More than 1 break ? Not sorted or rotated
            }
        }
        return true; // Either sorted normally or sorted & rotated
    }
};

