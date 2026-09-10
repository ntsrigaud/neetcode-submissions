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
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto* cur = root;

        // Branch until cur is one of the node OR is between them
        while (cur != nullptr) {
            if (p->val > cur->val && q->val > cur->val) {
                cur = cur->right;
            } else if (p->val < cur->val && q->val < cur->val) {
                cur = cur->left;
            } else {
                // Split or one of them is the LCA
                return cur;
            }
        }

        return cur;  // For safety, but should not be ever be reached
    }
};
