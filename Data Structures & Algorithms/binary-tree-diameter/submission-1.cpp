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
        int max_diameter = 0;

        // Reference recursive lambda fx inside its own body
        auto getDepth = [&](auto& self, TreeNode* node) -> int {
            if (node == nullptr) return 0;

            int d_left = self(self, node->left);
            int d_right = self(self, node->right);

            // Single post-order DFS for height and diameter computations
            max_diameter = std::max(max_diameter, d_left + d_right);

            return std::max(d_left, d_right) + 1;
        };

        getDepth(getDepth, root);

        return max_diameter;
    }
};
