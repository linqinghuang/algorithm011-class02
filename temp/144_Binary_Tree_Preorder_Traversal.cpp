class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        m_preorderTraversal(root, ans);
        return ans;
    }
private:
    void m_preorderTraversal(TreeNode* root, vector<int> & ans){
        if (root == nullptr){
            return;
        }
        ans.push_back(root->val);
        m_preorderTraversal(root->left, ans);
        m_preorderTraversal(root->right, ans);
    }
};