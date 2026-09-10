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
            const auto q_size = q.size();
            std::vector<int> level_values;
            level_values.reserve(q_size);

            // Pop and add all nodes for this level while adding their children
            for (size_t i = 0; i < q_size; ++i) {
                // Cache node ptr and pop front immediately
                auto* q_front = q.front();
                q.pop();

                level_values.push_back(q_front->val);

                // Enqueue the children if any
                if (q_front->left) q.push(q_front->left);
                if (q_front->right) q.push(q_front->right);
            }

            // CRITICAL -> Modify underlying buffer instead of deep copying
            tree_levels.push_back(std::move(level_values));
        }

        return tree_levels;
    }
};
