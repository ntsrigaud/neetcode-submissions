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
    void DFS(TreeNode* node, int& count, int max_val) {
        if (!node) return;
        if (node->val >= max_val) ++count;

        int new_max = std::max(max_val, node->val);

        DFS(node->left, count, new_max);
        DFS(node->right, count, new_max);
    }

   public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        // DFS while keeping track of max value
        int count = 0;
        DFS(root, count, root->val);

        return count;
    }
};
