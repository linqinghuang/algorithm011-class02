class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return ans;
        }
        generate(0, n);
        return ans;
    }
private:
    void generate(int index, int & n) {
        //terminator
        if (index == n * 2) {
            ans.push_back(element);
            return;
        }
        if (left < n) {
            element.push_back('(');
            left++;
            generate(index + 1, n);
            left--;
            element.pop_back();
        }
        if (left != 0 && right < left) {
            element.push_back(')');
            right++;
            generate(index + 1, n);
            right--;
            element.pop_back();
        }        
    }
    vector<string> ans;
    string element;
    int left = 0;
    int right = 0;
};