class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if (strs.empty()){
            return ans;
        }
        unordered_map<string, vector<string>> hash;
        for(auto str : strs){
            string originStr = str;
            sort(str.begin(), str.end());
            auto it = hash.find(str);
            if (it != hash.end()){
                it->second.push_back(originStr);
            }else{
                hash[str].push_back(originStr);
            }
        }
        for(auto &it : hash){
            ans.push_back(it.second);
        }
        return ans;
    }
};A