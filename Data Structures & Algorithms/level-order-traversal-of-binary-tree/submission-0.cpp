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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        std::vector<std::vector<int>> tree_levels;
        std::queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()) {
            auto q_size = q.size();
            std::vector<int> level_values;
            level_values.reserve(q_size);

            // Pop and add all nodes for this level while adding their children
            for (size_t i = 0; i < q_size; ++i) {
                auto* front = q.front();
                level_values.push_back(front->val);

                // Enqueue the children if any
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);

                // Remove front to complete cur level
                q.pop();
            }

            // Save sublist
            tree_levels.push_back(level_values);
        }

        return tree_levels;
    }
};
