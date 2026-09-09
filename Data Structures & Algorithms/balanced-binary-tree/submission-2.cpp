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
    int height(TreeNode* node) {
        if (node == nullptr) return 0;

        int h_left = height(node->left);
        int h_right = height(node->right);

        return std::max(h_left, h_right) + 1;
    }

    bool isNodeBalanced(TreeNode* node) {
        if (node == nullptr) return true;

        int h_left = height(node->left);
        int h_right = height(node->right);

        return std::abs(h_left - h_right) <= 1;
    }

   public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        bool is_left_balanced = isNodeBalanced(root->left);
        if (!is_left_balanced) return false;
        bool is_right_balanced = isNodeBalanced(root->right);

        return is_right_balanced && isNodeBalanced(root);
    }
};
