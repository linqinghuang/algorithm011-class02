class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) {
            return "";
        }
        if (n == 1) {
            return s;
        }
        string ans = "";
        int ansLegnth = 0;
        bool dp[n][n];
        //memset(dp, true, sizeof(bool) * n * n);
        for (int gap = 0; gap < n; gap++) {
            for (int i = 0; i < n - gap; i++) {
                int j = i + gap;
                if (gap == 0) {
                    dp[i][j] = true;
                }
                else if (gap == 1) {
                    dp[i][j] = (s[i] == s[j]);
                }else {
                    dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j]);
                }
                if (dp[i][j] && gap + 1 > ansLegnth) {
                    ansLegnth = gap + 1;
                    ans = s.substr(i, gap + 1);
                }
            }
        }
        return ans;
    }
};