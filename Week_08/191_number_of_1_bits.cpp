class Solution {
public:
    int hammingWeight(uint32_t n) {
        //return n ? 1 + hammingWeight(n & (n - 1)) : 0;
        int ans = 0;
        while (n != 0) {
            ans++;
            n &= n - 1;
        }
        return ans;
    }
};