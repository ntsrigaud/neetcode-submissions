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
    int DFS(TreeNode* node, int& res) {
        if (!node) return 0;

        // Compute max path on subtrees w/o splits
        int left_max = std::max(DFS(node->left, res), 0);
        int right_max = std::max(DFS(node->right, res), 0);

        // Max path to parent node with split
        int max_with_split = node->val + left_max + right_max;
        res = std::max(res, max_with_split);

        // Return max path w/o split including root
        return node->val + std::max(left_max, right_max);
    }

   public:
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        DFS(root, res);

        return res;
    }
};
