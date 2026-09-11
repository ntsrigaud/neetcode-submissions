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
    bool isValid(TreeNode* node, TreeNode* left = nullptr, TreeNode* right = nullptr) {
        if (!node) return true;

        if (left && left->val >= node->val || right && right->val <= node->val) return false;

        return isValid(node->left, left, node) && isValid(node->right, node, right);
    }

   public:
    bool isValidBST(TreeNode* root) { return isValid(root); }
};
