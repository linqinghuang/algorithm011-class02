class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (!(i >= 0 && j >= 0 && i < board.size() && j < board[0].size()))
            return;
        if (board[i][j] == 'O')
            board[i][j] = 'Z';
        else return;
        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
    }
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if ((i == 0 || j == 0 || i == board.size() - 1 || j == board[i].size() - 1) && (board[i][j] == 'O'))
                    dfs(board, i, j);

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'Z')
                    board[i][j] = 'O';
        return;
    }
};