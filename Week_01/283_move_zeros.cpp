class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty()) return;
        int zeroNums = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != 0){
                nums[j] = nums[i];
                j++;
            }else{
                zeroNums++;
            }
        }
        nums.erase(nums.begin() + j, nums.end());
        nums.insert(nums.end(), zeroNums, 0);
    }
};