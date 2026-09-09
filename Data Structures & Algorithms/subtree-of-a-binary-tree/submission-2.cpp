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
    bool isSame(TreeNode* p, TreeNode* q) {
        if (!p || !q) return p == q;
        if (p->val != q->val) return false;
        return isSame(p->left, q->left) && isSame(p->right, q->right);
    }

   public:
    bool isSubtree(TreeNode* root, TreeNode* sub_root) {
        if (!root) return false;  // Cannot have subtrees if you're null

        if (isSame(root, sub_root)) return true;

        return isSubtree(root->left, sub_root) || isSubtree(root->right, sub_root);
    }
};
