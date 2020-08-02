/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        buildHash(inorder);
        return _buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
private:
    TreeNode* _buildTree(vector<int>& preorder, int i, int j, vector<int>& inorder, int m, int n) {
        if (i > j) {
            return nullptr;
        }
        auto it = hash.find(preorder[i]);
        int leftSize = it->second - m;
        TreeNode* root = new TreeNode(it->first);
        root->left = _buildTree(preorder, i + 1, i + leftSize, inorder, m , it->second - 1);
        root->right = _buildTree(preorder, i + leftSize + 1, j, inorder, it->second + 1, n);
        return root;
    }
    void buildHash(vector<int> & order) {
        for(int i = 0; i < order.size(); i++) {
            hash.insert({order[i], i});
        }
    }
    unordered_map<int, int> hash;
};