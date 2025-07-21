#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool compare(string a, string b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        // Convert all integers to strings
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }

        // Sort using custom comparator
        sort(strNums.begin(), strNums.end(), compare);

        // Edge case: if the largest number is 0, return "0"
        if (strNums[0] == "0") return "0";

        // Concatenate all sorted strings
        string result;
        for (string s : strNums) {
            result += s;
        }

        return result;
    }
};
