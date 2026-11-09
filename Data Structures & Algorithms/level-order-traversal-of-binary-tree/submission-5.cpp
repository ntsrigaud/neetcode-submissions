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

    void preOrderDFS(TreeNode* cur, std::vector<std::vector<int>>& tree_levels,
                     int depth = 0) {
        if (!cur)
            return;

        // Create list for new level
        if (tree_levels.size() == depth)
            tree_levels.emplace_back();

        // Record level values at their depth
        tree_levels[depth].push_back(cur->val);

        // Record their children
        preOrderDFS(cur->left, tree_levels, depth + 1);
        preOrderDFS(cur->right, tree_levels, depth + 1);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};

        std::vector<std::vector<int>> tree_levels;
        preOrderDFS(root, tree_levels);

        return tree_levels;
    }
};