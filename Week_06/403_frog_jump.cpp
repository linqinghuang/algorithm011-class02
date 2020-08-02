/*
动态规划
    一步步计算 并用set去存储到达位置的步数大小
*/
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int size = stones.size();
        int n = stones[size - 1];
        if((1 + size) * size / 2 < n)
            return false;
        vector<set<int>> dp(n + 1);
        dp[1].insert(1);
        for(int i = 1; i < size; i++){
            for(int k : dp[stones[i]]){
                if(stones[i] + k - 1 <= n)
                    dp[stones[i] + k - 1].insert(k - 1);
                if(stones[i] + k <= n)
                    dp[stones[i] + k].insert(k);
                if(stones[i] + k + 1 <= n)
                    dp[stones[i] + k + 1].insert(k + 1);
            }
        }
        return !dp[n].empty();
    }
};