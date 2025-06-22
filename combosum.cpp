

class Solution {
public:
    void findCombination(int index, int target, const vector<int>& arr, vector<vector<int>>& result, vector<int>& current) {
        if (index == arr.size()) {
            if (target == 0) result.push_back(current);
            return;
        }

        // Pick the element
        if (arr[index] <= target) {
            current.push_back(arr[index]);
            findCombination(index, target - arr[index], arr, result, current);
            current.pop_back();
        }

        // Skip the element
        findCombination(index + 1, target, arr, result, current);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        findCombination(0, target, candidates, result, current);
        return result;
    }
};

