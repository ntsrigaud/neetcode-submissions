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
    int dfs(TreeNode* node, int& res) {
        if (!node) return 0;

        // Retrieve LR max paths without split
        int l_max = std::max(dfs(node->left, res), 0);
        int r_max = std::max(dfs(node->right, res), 0);

        // Compute max path sum with split
        res = std::max(res, node->val + l_max + r_max);

        // One or the other -> not both
        return node->val + std::max(l_max, r_max);
    }

   public:
    int maxPathSum(TreeNode* root) {
        int result = root->val;

        dfs(root, result);
        return result;
    }
};
