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
    static constexpr int UNBALANCED = -1;

    int height(TreeNode* node) {
        if (node == nullptr) return 0;

        // Combine height computation and balanced verification
        // into single post order traversal -> Bottom-up DFS
        int h_left = height(node->left);
        if (h_left == UNBALANCED) return UNBALANCED;

        int h_right = height(node->right);
        if (h_right == UNBALANCED) return UNBALANCED;

        if (std::abs(h_left - h_right) > 1) return UNBALANCED;

        return std::max(h_left, h_right) + 1;
    }

   public:
    bool isBalanced(TreeNode* root) { return height(root) != UNBALANCED; }
};
