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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        // BFS and save last node at each level
        std::queue<TreeNode*> q;
        std::vector<int> right_side;

        q.push(root);
        while (!q.empty()) {
            const auto level_size = q.size();

            for (size_t i = 0; i < level_size; ++i) {
                const auto* cur = q.front();
                q.pop();

                if (i == level_size - 1) right_side.push_back(cur->val);

                // Enqueue children
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }

        return right_side;
    }
};
