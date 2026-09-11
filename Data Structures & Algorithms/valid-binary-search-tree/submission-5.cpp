/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
    bool inOrderDFS(TreeNode* node, TreeNode*& prev) {
        if (!node) return true;

        auto isValid = inOrderDFS(node->left, prev);

        if (!isValid) return false;
        if (prev && prev->val >= node->val) return false;

        prev = node;

        return inOrderDFS(node->right, prev);
    }

   public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return inOrderDFS(root, prev);
    }
};
