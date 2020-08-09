class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        //backtracking
        if (n == 0) {
            return ans;
        }
        vector<string> element(n, string(n, '.'));        
        totalNum = n;
        backtrack(0, element);
        return ans;
    }
private:
    void backtrack(int row, vector<string> & element) {
        if (row == totalNum) {
            ans.push_back(element);
            return ;
        }
        for (int column = 0; column < totalNum; column++) {
            if (!isUnderAttack(element, row, column)) {
                element[row][column] = 'Q';
                //drill down
                backtrack(row + 1, element);
                //backtracking
                element[row][column] = '.';
            }else {
                continue;
            }
        }
    }
    bool isUnderAttack(vector<string>& element, int row, int column) {
        //check column
        for (int i = 0; i < row; i++) {
            if (element[i][column] == 'Q') {
                return true;
            }
        }
        //check right up
        for (int i = row - 1, j = column + 1; i >= 0 && j < totalNum; i--, j++) {
            if (element[i][j] == 'Q') {
                return true;
            }
        }
        //check left up
        for (int i = row - 1, j = column -  1; i >= 0 && j >= 0; i--, j--) {
            if (element[i][j] == 'Q') {
                return true;
            }
        }
        return false;
    }

    vector<vector<string>> ans;
    int totalNum = 0;
};