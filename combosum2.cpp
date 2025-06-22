class Solution {
public:
    void findCombination(int ind, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        
        for (int i = ind; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > ind && candidates[i] == candidates[i - 1]) continue;
            
            // Early stopping
            if (candidates[i] > target) break;
            
            ds.push_back(candidates[i]);
            findCombination(i + 1, target - candidates[i], candidates, ans, ds);
            ds.pop_back();  // Backtrack
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Required to skip duplicates
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};
