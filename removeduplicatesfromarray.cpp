#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        if (arr.empty()) return 0; // Edge case: Empty array

        int i = 0;
        for (int j = 1; j < arr.size(); j++) { 
            if (arr[j] != arr[i]) { 
                i++;
                arr[i] = arr[j]; // Move unique elements forward
            }
        }
        return i + 1; // New array size
    }
};

