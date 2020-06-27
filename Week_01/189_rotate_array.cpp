class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if (k > size) {
            k = k % size;
        }
        if (k != 1){
            /*
            由于vector的insert的操作会使得迭代器失效，因此需要使用额外空间。
            这里提高了代码空间复杂度
            */
            vector<int> extraSpace(nums.begin() + size - k, nums.end());
            nums.insert(nums.begin(), extraSpace.begin(), extraSpace.end());
        }else{
            nums.insert(nums.begin(), nums[size - 1]);
        }
        
        nums.erase(nums.begin() + size, nums.end());
    }
};