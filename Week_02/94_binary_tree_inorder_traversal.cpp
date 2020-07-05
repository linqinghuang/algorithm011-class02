class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        m_inorderTraversal(root, ans);
        return ans;
    }
private:
    void m_inorderTraversal(TreeNode* root, vector<int>& ans){        
        if (root == nullptr){
            return;
        }
        m_inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        m_inorderTraversal(root->right, ans);
    }
};