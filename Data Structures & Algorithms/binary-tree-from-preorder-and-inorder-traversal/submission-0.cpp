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
    int pre_idx = 0;

    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder,
                        std::unordered_map<int, int>& in_map, int in_start, int in_end) {
        if (in_start >= in_end) return nullptr;

        // Root is the first element of the preorder array
        int root_val = preorder[pre_idx++];
        auto* root = new TreeNode(root_val);

        // Split inorder array at mid idx (map avoid linear lookup)
        int mid = in_map[root_val];

        // Build the left subtree with the nodes to the left of mid
        root->left = buildTree(preorder, inorder, in_map, in_start, mid);

        // Build the right subtree with the node to the right of mid
        root->right = buildTree(preorder, inorder, in_map, mid + 1, in_end);

        return root;
    }

   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;

        // Map node values to their inorder indices
        // to avoid linear lookup per node
        std::unordered_map<int, int> in_map;
        auto len = static_cast<int>(inorder.size());
        for (int i = 0; i < len; ++i) in_map[inorder[i]] = i;

        pre_idx = 0;
        return buildTree(preorder, inorder, in_map, 0, len);
    }
};
