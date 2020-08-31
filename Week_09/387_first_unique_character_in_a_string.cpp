class Solution {
public:
    int firstUniqChar(string s) {
        if (s.empty()) {
            return -1;
        }
        int length = s.size();
        int table[26] = {0};
        for (int i = 0; i < length; i++) {
            table[s[i] - 'a']++;
        }
        for (int j = 0; j < length; j++) {
            if (table[s[j] - 'a'] == 1) {
                return j;
            }
        }
        return -1;
    }
};