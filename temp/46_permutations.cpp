class Solution {
public:
    //use backtracking
    vector<vector<int>> permute(vector<int>& nums) {
        totalNum = nums.size();
        if (totalNum == 0){
            return ans;
        }
        backtracking(nums, totalNum);
        return ans;
    }
private:
    void backtracking(vector<int>& nums, int k){
        //terminator
        if (k == 0) {
            ans.push_back(element);
            return;
        }
        for (int i = 0; i < totalNum; i++) {
            auto it = hash.find(nums[i]);
            if (it != hash.end()) {
                continue;
            }
            element.push_back(nums[i]);
            hash[nums[i]]++;
            backtracking(nums, k - 1);
            //backtracking
            element.pop_back();
            hash.erase(nums[i]);
        }
    }
    vector<vector<int>> ans;
    unordered_map<int, int> hash;
    vector<int> element;
    int totalNum = 0;
};