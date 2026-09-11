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
    bool inOrderDFS(TreeNode* node, std::vector<int>& values) {
        if (!node) return true;

        auto isValid = inOrderDFS(node->left, values);

        if (!isValid) return false;
        if (!values.empty() && values.back() >= node->val) return false;

        values.push_back(node->val);

        return inOrderDFS(node->right, values);
    }

   public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        std::vector<int> values;
        return inOrderDFS(root, values);
    }
};
