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
    int max_diameter = 0;

    int getDepth(TreeNode* node) {
        if (node == nullptr) return 0;

        int d_left = getDepth(node->left);
        int d_right = getDepth(node->right);

        // Single post-order DFS for height and diameter computations
        max_diameter = std::max(max_diameter, d_left + d_right);

        return std::max(d_left, d_right) + 1;
    }

   public:
    int diameterOfBinaryTree(TreeNode* root) {
        getDepth(root);

        return max_diameter;
    }
};
