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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;

        auto dfs = [&](auto& self, TreeNode* cur) -> int {
            if (!cur) return 0;

            const int h_left = self(self, cur->left);
            const int h_right = self(self, cur->right);

            // Update the diameter if greater
            diameter = std::max(diameter, h_left + h_right);

            // Return height
            return 1 + std::max(h_left, h_right);
        };

        dfs(dfs, root);

        return diameter;
    }
};
