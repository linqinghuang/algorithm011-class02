class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (g.empty() || s.empty()) {
            return 0;
        }
        //give cookie to the smallest greed child first
        //Greedy here
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int childIndex = 0;
        int cookieIndex = 0;
        while (childIndex < g.size() && 
               cookieIndex < s.size()) {
            if (g[childIndex] <= s[cookieIndex]) {
                childIndex++;
                cookieIndex++;
            }else {
                cookieIndex++;
            }
        }
        return childIndex;
    }
};