/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    static constexpr int INVALID = -1;

   public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> s;
        auto* cur = root;

        while (cur || !s.empty()) {
            // Go left as far as possible
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }

            // Get the leftmost node
            cur = s.top();
            s.pop();

            --k;
            if (k == 0) return cur->val;

            // Check the right side
            cur = cur->right;
        }

        return INVALID;
    }
};
