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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};

        std::vector<std::vector<int>> tree_levels;

        // Record the nodes as you go down to each level w/o a queue
        auto preOrderDFS = [&](auto& self, TreeNode* cur,
                               int depth = 0) -> void {
            if (!cur)
                return;

            // Create placeholder list for new level
            if (tree_levels.size() == depth)
                tree_levels.emplace_back();

            // Record level node values
            tree_levels[depth].push_back(cur->val);

            self(self, cur->left, depth + 1);
            self(self, cur->right, depth + 1);
        };

        preOrderDFS(preOrderDFS, root, 0);

        return tree_levels;
    }
};