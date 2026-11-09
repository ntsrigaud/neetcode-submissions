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

        std::vector<std::vector<int>> res;
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            // Record the size of the original queue -> Level size
            const int level_size = q.size();

            // Record the level nodes and values
            std::vector<int> level_values;
            for (int i = 0; i < level_size; ++i) {
                // Pop and record children
                const auto* front = q.front();
                q.pop();

                level_values.push_back(front->val);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }

            // Record the level node values
            res.emplace_back(std::move(level_values));
        }

        return res;
    }
};
