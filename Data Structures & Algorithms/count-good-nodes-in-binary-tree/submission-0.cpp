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
    void DFS(TreeNode* node, int cur_max, int& count) {
        if (!node) return;

        if (node->val >= cur_max) ++count;
        DFS(node->left, std::max(cur_max, node->val), count);
        DFS(node->right, std::max(cur_max, node->val), count);
    }

   public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        int cur_max = root->val;
        int count = 0;
        DFS(root, cur_max, count);

        return count;
    }
};
