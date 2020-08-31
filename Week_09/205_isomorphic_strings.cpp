class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.empty()) return true;
        int cnts[128] = {};
        int cntc[128] = {};
        for (int i = 0; i < s.size(); i++) {
            if (cnts[s[i]] == 0) cnts[s[i]] = t[i];
            else if (cnts[s[i]] != t[i]) return false;
            if (cntc[t[i]] == 0) cntc[t[i]] = s[i];
            else if (cntc[t[i]] != s[i]) return false;
        }
        return true;
    }
};