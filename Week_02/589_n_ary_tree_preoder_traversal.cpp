class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ve;
        if (!root) return ve;

        stack<Node*> st;
        st.push(root);
        while(!st.empty()) {
            Node *node = st.top();
            st.pop();

            if (node) {
                ve.emplace_back(node->val);
            }else {
                continue;
            }

            if (!node->children.empty()) {
                int size = node->children.size();
                for (int i=size-1; i>=0; i--) { // 注意：这里要倒序 stack LIFO
                    Node *n = node->children[i];
                    if (n) st.push(n);
                }
            }
        }
        return ve;
    }
};