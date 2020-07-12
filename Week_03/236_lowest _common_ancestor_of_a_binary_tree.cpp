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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* ans = nullptr;
        stack<TreeNode*> pStack;
        stack<TreeNode*> qStack;
        findTreeNode(pStack, root, p->val);
        isFound = false;
        findTreeNode(qStack, root, q->val);
        unordered_map<int, TreeNode*> pHash;
        while (!pStack.empty()) {
            pHash.insert({pStack.top()->val, pStack.top()});
            pStack.pop();
        }
        while (!qStack.empty()) {
            auto it = pHash.find(qStack.top()->val);
            if (it != pHash.end()) {
                ans = qStack.top();
                break;
            }else {
                qStack.pop();
            }
        }
        return ans;
    }
private:
    void findTreeNode(stack<TreeNode*>& s, TreeNode* root, int& val){
        //terminator
        if (root == nullptr || isFound == true) {
            return;
        }
        //process
        if (root->val != val) {
            s.push(root);
            //dirll down
            findTreeNode(s, root->left, val);
            //target not found, clear stack
            if (!isFound) {
                while (s.top() != root) {
                    s.pop();
                }
            }
            findTreeNode(s, root->right, val);
            if (!isFound) {
                while (s.top() != root) {
                    s.pop();
                }
            }
        }else {
            //found target
            s.push(root);
            isFound = true;
            return;
        }
    }
    bool isFound = false;
};