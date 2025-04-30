class Solution {
public:
    bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;

    int mapS[256] = {0}; // Maps characters from s
    int mapT[256] = {0}; // Maps characters from t

    for (int i = 0; i < s.length(); i++) {
        char cs = s[i], ct = t[i];

        if (mapS[cs] != mapT[ct]) return false;

        mapS[cs] = i + 1;
        mapT[ct] = i + 1;
    }

    return true;


    }
};
