/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
    static constexpr int INVALID = -1;

public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<const TreeNode*> st;
        const auto* cur = root;

        while (cur || !st.empty()) {
            // Travel to leftmost node
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }

            // Process next smallest node in-order
            cur = st.top();
            st.pop();

            if (--k == 0)
                return cur->val;

            // Proceed to the right
            cur = cur->right;
        }

        return INVALID;
    }
};
