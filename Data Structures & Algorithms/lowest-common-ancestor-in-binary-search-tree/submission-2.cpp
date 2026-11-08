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
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto* cur = root;

        // Binary search -> LCA should be in the middle if not one of them
        while (cur) {
            if (p->val > cur->val && q->val > cur->val)
                cur = cur->right;
            else if (p->val < cur->val && q->val < cur->val)
                cur = cur->left;
            else
                return cur;
        }

        return nullptr;  // Should not be reached
    }
};
