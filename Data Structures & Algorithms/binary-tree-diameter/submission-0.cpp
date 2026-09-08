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
    int depth(TreeNode* node) {
        if (node == nullptr) return 0;

        int d_left = depth(node->left);
        int d_right = depth(node->right);

        return std::max(d_left, d_right) + 1;
    }

   public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        int diam_left = diameterOfBinaryTree(root->left);
        int diam_right = diameterOfBinaryTree(root->right);

        auto b_max_diam = std::max(diam_left, diam_right);

        int depth_left = depth(root->left);
        int depth_right = depth(root->right);

        return std::max(b_max_diam, depth_left + depth_right);
    }
};
