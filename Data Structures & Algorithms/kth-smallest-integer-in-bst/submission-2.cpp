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

    int inOrderTrav(TreeNode* node, std::vector<int>& arr, int k) {
        if (!node) return INVALID;

        auto res = inOrderTrav(node->left, arr, k);
        if (res != INVALID) return res;

        arr.push_back(node->val);
        if (static_cast<int>(arr.size()) == k) return node->val;

        return inOrderTrav(node->right, arr, k);
    }

   public:
    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> arr;

        return inOrderTrav(root, arr, k);
    }
};
