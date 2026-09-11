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
    void inOrderDFS(TreeNode* node, std::vector<int>& values) {
        if (!node) return;

        inOrderDFS(node->left, values);
        values.push_back(node->val);
        inOrderDFS(node->right, values);
    }

   public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        std::vector<int> values;
        inOrderDFS(root, values);

        // Check the sorting order
        for (size_t i = 1; i < values.size(); ++i) {
            if (values[i] <= values[i - 1]) {
                return false;
            }
        }

        return true;
    }
};
