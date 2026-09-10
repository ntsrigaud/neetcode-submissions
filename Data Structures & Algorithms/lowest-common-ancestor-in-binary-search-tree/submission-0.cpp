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
        if (!root)
            return nullptr;
        // Top-down search of the two nodes from each nodes

        // Stop checking a node if its value is one of the descendants
        // Or if it is in between them
        bool in_between = p->val < root->val && q->val > root->val ||
                          q->val < root->val && p->val > root->val;
        if (root->val == p->val || root->val == q->val || in_between) {
            // Cannot find any other LCA that has both of them
            return root;
        }

        // Check the range to select which branch to traverse
        if (p->val > root->val && q->val > root->val) {
            // Both are greater -> Branch to right
            return lowestCommonAncestor(root->right, p, q);
        }

        // Both are lower -> Branch to left
        return lowestCommonAncestor(root->left, p, q);
    }
};
