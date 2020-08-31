class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) {
            return s;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                continue;
            }
            int end = i + 1;
            while (end < s.size() && s[end] != ' ') {
                end++;
            }
            reverse(s.begin() + i, s.begin() + end);
            i = end;
        }
        return s;
    }
};