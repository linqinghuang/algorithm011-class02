class TrieNode{
    
public:
    bool is_word;
    string str;
    vector<TrieNode*> ne;
    
    TrieNode(){
        is_word = false;
        ne = vector<TrieNode*>(26, nullptr);
    }
};



class Solution {
public:
    
    TrieNode* root;
    int n, m;
    vector<string> ans;
    vector<vector<char>> data;
    unordered_set<string> tmp;
    vector<vector<bool>> vis;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    void add(string& word) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (cur -> ne[c - 'a'] == nullptr) cur -> ne[c - 'a'] = new TrieNode();
            cur = cur -> ne[c - 'a'];
        }
        cur -> is_word = true;
        cur -> str = word;
    }
    
    void dfs(int x, int y, TrieNode* cur) {
        if (cur -> is_word) {
            if (!tmp.count(cur -> str)) {
                ans.push_back(cur -> str);
                tmp.insert(cur -> str);
            }
        }
        for (int i = 0; i < 4; i ++) {
                int xx = dx[i] + x, yy = dy[i] + y;
                if (xx < 0 || xx >= n || yy < 0 || yy >= m || vis[xx][yy]) continue;
                if (cur -> ne[data[xx][yy] - 'a']) {
                    vis[xx][yy] = true;
                    dfs(xx, yy, cur -> ne[data[xx][yy] - 'a']);
                    vis[xx][yy] = false;
                }
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        data = board;
        ans = vector<string>();
        for (auto x : words) add(x);
        n = board.size();
        if (n == 0) return {};
        m = board[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m, false));
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (root -> ne[board[i][j] - 'a']) {
                    vis[i][j] = true;
                    dfs(i, j, root -> ne[board[i][j] - 'a']);
                    vis[i][j] = false;
                }
            }
        }
        return ans;
    }
};