class Solution {
    int check(const string& str, int start, int end)
    {
        int res = 0;
        if (start == end)
        {
            ++res;
            --start;
            ++end;
        }
        while (start >= 0 && end < str.size())
        {
            if (str[start--] != str[end++])
                break;
            res += 2;
        }
        return res;
    }
public:
    int countSubstrings(string s) {
        int len = s.size();
        int res = len;
        for (int i = 0; i < len * 2 - 1; ++i)
        {
            int cur = check(s, i >> 1, (i + 1) >> 1);
            res += (cur >> 1);
        }
        return res;
    }
};