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
    static constexpr int INVALID = -1;

    bool inOrderDFS(TreeNode* node, int& kth_smallest, int& k) {
        if (!node) return false;

        auto isFound = inOrderDFS(node->left, kth_smallest, k);
        if (isFound) return true;

        // Stop recursion
        if (--k == 0) {
            kth_smallest = node->val;
            return true;
        }

        return inOrderDFS(node->right, kth_smallest, k);
    }

   public:
    int kthSmallest(TreeNode* root, int k) {
        int kth_smallest = INVALID;

        inOrderDFS(root, kth_smallest, k);

        return kth_smallest;
    }
};
