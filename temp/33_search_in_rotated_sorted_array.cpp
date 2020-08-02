class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        if (nums.size() == 1) nums[0] == target ? 0 : -1;
        int mid = 0;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[left] <= nums[mid]) {
                if (target > nums[mid] || target < nums[left]) {
                    left = mid + 1;
                }else {
                    right = mid - 1;
                }
            }else {
                if (target < nums[mid + 1] || target > nums[right]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};