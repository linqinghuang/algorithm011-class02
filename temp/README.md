class Solution {
public:
    int search(vector<int>& nums, int target) {
        int errorIndex = 0;
        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
            errorIndex = (left + right) / 2;
            if (nums[errorIndex] == target) {
                return errorIndex;
            }
            if (nums[left] < nums[errorIndex]) {
                if (nums[errorIndex] > nums[errorIndex + 1]) {
                    return errorIndex;
                }else {
                    left = errorIndex + 1;
                }
            }else {
                if (nums[errorIndex] < nums[errorIndex - 1]) {
                    return errorIndex;
                }else {
                    right = errorIndex - 1;
                }
            }
        }
        return -1;
    }
};