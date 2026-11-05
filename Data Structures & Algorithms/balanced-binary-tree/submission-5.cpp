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
    bool isBalanced(TreeNode* root) {
        auto getHeight = [](auto& self, TreeNode* node) -> int {
            if (!node) return 0;

            int h_left = self(self, node->left);

            // Early stopping if unbalanced
            if (h_left < 0) return -1;

            int h_right = self(self, node->right);

            // Early stopping and balance condition
            if (h_right < 0 || std::abs(h_left - h_right) > 1) return -1;

            return std::max(h_left, h_right) + 1;
        };

        return getHeight(getHeight, root) >= 0;
    }
};
