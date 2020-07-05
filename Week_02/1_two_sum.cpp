class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //unsigned int length = nums.size();
        unordered_map<int, int> hash;
        hash[nums[0]] = 0;
        for(int i = 1; i< nums.size(); i++){
            auto iter = hash.find((target - nums[i]));
            if((iter != hash.end()) && iter->second != i){
                return {iter->second, i};
            }
            if(iter == hash.end()){
                hash[nums[i]] = i;
                continue;
            }
        }
        return {0,0};
    }
};