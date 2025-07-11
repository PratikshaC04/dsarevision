class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> mp;
        int result = INT_MAX;

        for (int i = 0 ; i < cards.size(); i++) {
            if(mp.find(cards[i]) != mp.end()) {
                result = min (result, i - mp[cards[i]] + 1);
            }
            mp[cards[i]] = i;
        }
        return (result == INT_MAX)? -1 : result;
    }
};