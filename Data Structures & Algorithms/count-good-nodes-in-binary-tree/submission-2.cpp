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
    void preOrderDFS(TreeNode* node, int cur_max, int& count) {
        if (!node) return;

        if (node->val >= cur_max) ++count;
        cur_max = std::max(cur_max, node->val);

        preOrderDFS(node->left, cur_max, count);
        preOrderDFS(node->right, cur_max, count);
    }

   public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        int cur_max = root->val;
        int count = 0;

        preOrderDFS(root, cur_max, count);

        return count;
    }
};
