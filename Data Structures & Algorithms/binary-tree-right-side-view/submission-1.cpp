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
    void rightFirstDFS(TreeNode* node, std::vector<int>& right_view, size_t depth) {
        if (!node) return;

        if (right_view.size() == depth) {
            right_view.push_back(node->val);
        }

        // Right-First DFS
        rightFirstDFS(node->right, right_view, depth + 1);
        rightFirstDFS(node->left, right_view, depth + 1);
    }

   public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> right_side_view;

        rightFirstDFS(root, right_side_view, 0);

        return right_side_view;
    }
};
