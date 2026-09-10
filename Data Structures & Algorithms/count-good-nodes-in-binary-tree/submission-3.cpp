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
    int preOrderDFS(TreeNode* node, int cur_max) {
        if (!node) return 0;

        int res = !!(node->val >= cur_max);
        cur_max = std::max(cur_max, node->val);

        return res + preOrderDFS(node->left, cur_max) + preOrderDFS(node->right, cur_max);
    }

   public:
    int goodNodes(TreeNode* root) { return preOrderDFS(root, root->val); }
};
