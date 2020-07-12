class Solution {
public:
    //avoid repeating is the key
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        totalNum = nums.size();
        if (totalNum == 0) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        vector<bool> used(totalNum, false);
        backtrack(nums, 0, used);
        return ans;
    }
private:
    void backtrack(vector<int>& nums, int depth, vector<bool> & used) {
        //terminator
        if (depth == totalNum) {
            ans.push_back(element);
            return;
        }
        //process
        for (int i = 0; i < totalNum; i++) {
            if (used[i]) {
                continue;
            }
            //pruning
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            element.push_back(nums[i]);
            used[i] = true;
            //drill down
            backtrack(nums, depth + 1, used);
            //backtrack
            used[i] = false;
            element.pop_back();
        }
    }
    vector<vector<int>> ans;
    vector<int> element;
    int totalNum = 0;
};