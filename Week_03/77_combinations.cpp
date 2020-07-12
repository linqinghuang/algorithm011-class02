class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n < k || n <= 0 || k <= 0) {
            return ans;
        }
        totalNum = n;
        _combine(1, k);
        return ans;
    }
private:
    void _combine(int first, int k) {
        //terminator
        if (k == 0) {
            ans.push_back(element);
            return;
        }              
        for (int i = first; i <= totalNum; i++) {
            //process
            element.push_back(i);
            //drill down
            _combine(i + 1, k - 1);
            //backtrack
            element.pop_back();
        }
    }
    vector<vector<int>> ans;
    vector<int> element;
    int totalNum = 0;
};