class Solution {
public:
    bool isvalidpalindrome(string s){
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    void fun(string &s,int idx,vector<vector<string>>&ans,vector<string>&temp){
        int l=s.length();
        if(idx==l){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<l;i++){
            string str=s.substr(idx,i-idx+1);
            if(isvalidpalindrome(str)){
                temp.push_back(str);
                fun(s,i+1,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        fun(s,0,ans,temp);
        return ans;
    }
};