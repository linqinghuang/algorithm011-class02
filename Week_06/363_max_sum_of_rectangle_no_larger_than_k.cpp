class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        if(m == 0 || matrix[0].size() == 0) return 0;
        int n = matrix[0].size();

        // i 代表矩形的起始行
        int ans = INT_MIN;

        // 起始列
        for(int i = 0; i < n; i++){
            // 终止列
            vector<int> rowCums(m, 0);
            for(int j = i; j < n; j++){
                set<int> pres;
                int preSum = 0;
                for(int r = 0; r < m; r++){
                    rowCums[r] += matrix[r][j];
                    preSum += rowCums[r];

                    if(preSum <= k) ans = max(ans, preSum);

                    auto it = pres.lower_bound(preSum - k);
                    if(it != pres.end() ){ ans = max(ans, preSum - *it); }
                    pres.insert(preSum);
                }
            }
        }
        return ans;
    }
};