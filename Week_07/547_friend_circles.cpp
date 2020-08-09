class Solution {
public:    
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if (n == 0) {
            return 0;
        }
        vector<int> parent(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 1 && i != j) {
                    unit(parent, i, j);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                count++;
            }
        }
        return count;
    }
private:
    int find(vector<int>& parent, int i) {
        if (parent[i] == -1){
            return i;
        }
        return find(parent, parent[i]);
    }
    void unit(vector<int>& parent, int i, int j) {
        int xset = find(parent, i);
        int yset = find(parent, j);
        if (xset != yset) {
            parent[xset] = yset;
        }
    }
    
};