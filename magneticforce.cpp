#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceBalls(vector<int>& position, int dist, int m) {
        int n = position.size();
        int count = 1; // Place the first ball
        int lastPos = position[0];
        for (int i = 1; i < n; i++) {
            if (position[i] - lastPos >= dist) {
                count++;
                lastPos = position[i];
            }
            if (count >= m) return true;
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        
        int low = 1, high = position[n - 1] - position[0];
        int ans = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlaceBalls(position, mid, m)) {
                ans = mid; // store the answer
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};

