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
    void preOrderDFS(TreeNode* node, std::vector<std::vector<int>>& levels, size_t depth) {
        if (!node) return;

        if (levels.size() == depth) {
            levels.emplace_back();
        }

        levels[depth].push_back(node->val);

        preOrderDFS(node->left, levels, depth + 1);
        preOrderDFS(node->right, levels, depth + 1);
    }

    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> levels;
        preOrderDFS(root, levels, 0);
        return levels;
    }

   public:
    vector<int> rightSideView(TreeNode* root) {
        auto tree_levels = levelOrder(root);
        std::vector<int> right_side_view;
        right_side_view.reserve(tree_levels.size());

        // Find the end of each level
        for (const auto& level : tree_levels) {
            right_side_view.push_back(level.back());
        }

        return right_side_view;
    }
};
