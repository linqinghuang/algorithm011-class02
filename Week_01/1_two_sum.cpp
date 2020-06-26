class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;
        vector<int> retVector;
        for(int i = 0; i < nums.size(); i++){
            hashTable.insert({nums[i], i});
        }
        for (int j = 0; j < nums.size(); j++) {
            auto it = hashTable.find(target - nums[j]);
            if (it != hashTable.end() && j != it->second) {
                retVector.push_back(j);
                retVector.push_back(it->second);
                return retVector;
            }
        }
        return retVector;
    }
};