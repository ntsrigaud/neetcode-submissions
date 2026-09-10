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
    void preOrderDFS(TreeNode* node, std::vector<std::vector<int>>& tree_levels, size_t depth) {
        if (!node) return;

        if (tree_levels.size() == depth) {
            tree_levels.emplace_back();  // Create an empty list for cur level
        }

        // Record nodes at their specific seen depth
        tree_levels[depth].push_back(node->val);

        preOrderDFS(node->left, tree_levels, depth + 1);
        preOrderDFS(node->right, tree_levels, depth + 1);
    }

   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        std::vector<std::vector<int>> tree_levels;
        preOrderDFS(root, tree_levels, 0);

        return tree_levels;
    }
};
