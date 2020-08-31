class Solution {
public:
    string reverseOnlyLetters(string S) {
        /*
        solution: double pointer
        time complexity: O(n)
        space complexity: O(1)
        */
        if (S.size() < 2) {
            return S;
        }
        int left = 0;
        int right = S.size();
        while (left < right) {
            while (left < right && !isalpha(S[left])) {
                left++;
            }
            while (left < right && !isalpha(S[right])) {
                right--;
            }
            swap(S[left], S[right]);
            left++;
            right--;
        }
        return S;
    }
};