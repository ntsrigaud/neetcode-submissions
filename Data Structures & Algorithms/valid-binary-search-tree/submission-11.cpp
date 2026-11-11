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
    bool DFS(TreeNode* node, int left, int right) {
        if (!node) return true;  // Empty BST is still valid
        if (node->val >= right || node->val <= left) return false;

        return DFS(node->left, left, node->val) && DFS(node->right, node->val, right);
    }

   public:
    bool isValidBST(TreeNode* root) { return DFS(root, INT_MIN, INT_MAX); }
};
