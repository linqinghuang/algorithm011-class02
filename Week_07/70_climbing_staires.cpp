class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) {
            return n;
        }
        //dp[i] = dp[i - 1] + dp[i - 2]
        int a = 1;
        int b = 1;
        int c = 2;
        for (int i = 1; i < n; i++) {
            c = b + a;
            a = b;
            b = c;
        }
        return c;
    }
};