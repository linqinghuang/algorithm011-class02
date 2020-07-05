class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == nullptr){
            return ans;
        }
        vector<int> levelVal;
        queue<Node*> dfsQueue;
        dfsQueue.push(root);
        while (!dfsQueue.empty()){
            int size = dfsQueue.size();
            for (int i = 0; i < size; i++) {                
                Node* curNode = dfsQueue.front();
                dfsQueue.pop();                
                levelVal.push_back(curNode->val);
                for (auto child : curNode->children) {
                    dfsQueue.push(child);
                }
            }
            ans.push_back(levelVal);
            levelVal.clear();
        }
        return ans;
    }
};