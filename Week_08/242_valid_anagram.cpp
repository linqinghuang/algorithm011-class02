class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        //put s into hashmap
        // unordered_map<char, int> hashTable;
        // for (int i = 0; i < s.size(); i++){
        //     hashTable[s[i]]++;
        // }
        // for (int j = 0; j < t.size(); j++){
        //     auto it = hashTable.find(t[j]);
        //     if (it != hashTable.end() &&  it->second != 0){
        //         it->second -= 1;
        //     }else{
        //         return false;
        //     }
        // }
        // use array instead of unordered_map
        int array[26] = {0};
        //int array[26];
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