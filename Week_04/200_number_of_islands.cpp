class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        rows = grid.size();
        columns = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    //bfs, set '1' to '0'
                    bfs(grid, i, j);
                } else {
                    continue;
                }
            }
        }
        return ans;
    }
private:
    void bfs(vector<vector<char>>& grid, int x, int y) {
        queue<pair<int, int>> islandQueue;
        islandQueue.push(make_pair(x, y));
        grid[x][y] = '0';
        while(!islandQueue.empty()) {
            pair<int, int> position = islandQueue.front();
            islandQueue.pop();

            x = position.first;
            y = position.second;
            //right
            if (y + 1 < columns && grid[x][y + 1] == '1'){
                islandQueue.push(make_pair(x, y + 1));
                grid[x][y + 1] = '0';
            }
            //down
            if (x + 1 < rows && grid[x + 1][y] == '1'){
                islandQueue.push(make_pair(x + 1, y));
                grid[x + 1][y] = '0';
            }
            //left
            if (y - 1 >= 0 && grid[x][y - 1] == '1'){
                islandQueue.push(make_pair(x, y - 1));
                grid[x][y - 1] = '0';
            }
            //up
            if (x - 1 >= 0 && grid[x - 1][y] == '1'){
                islandQueue.push(make_pair(x - 1, y));
                grid[x - 1][y] = '0';
            }
        }
    }
    int ans = 0;
    int rows = 0;
    int columns = 0;
};