class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        // use array instead of unordered_map
        int array[26] = {0};
        for (int i = 0; i < s.size(); i++){
            array[s[i] - 97] += 1;
        }
        for (int j = 0; j < t.size(); j++){
            array[t[j] - 97] -= 1;
            if (array[t[j] - 97] < 0){
                return false;
            }
        }
        return true;
    }
};