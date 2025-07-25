class Solution {
public:
   
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        vector<int>curr(t.size()+1, 0),prev(s.size()+1,0);
         vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1,0));
        for(int n=1 ;n<=s.size();n++){
            for(int m=1;m<=s.size();m++){
                 if(s[n-1]==t[m-1]) curr[m]=1+prev[m-1];
                 else curr[m]=max(prev[m], curr[m-1]);
            }
            prev=curr;
        }
        
        return s.size()-prev[s.size()];
    }
};