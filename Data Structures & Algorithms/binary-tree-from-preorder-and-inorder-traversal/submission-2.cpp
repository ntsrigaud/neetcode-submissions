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
    typedef struct Range {
        size_t start;
        size_t end;
    } Range; // -> [start, end)

    TreeNode* buildSubtree(const std::vector<int>& preorder,
                           const std::unordered_map<int, size_t>& inorder_idx,
                           Range p, Range i) {
        // Base case -> empty sub-range
        if (p.start >= p.end || i.start > i.end)
            return nullptr;

        const int root_val = preorder[p.start];
        TreeNode* root = new TreeNode(root_val);

        // O(1) lookup for root's position in inorder
        const size_t mid = inorder_idx.at(root_val);
        const size_t left_size = mid - i.start;

        root->left = buildSubtree(preorder, inorder_idx,
                                  {p.start + 1, p.start + 1 + left_size},
                                  {i.start, mid});
        root->right =
            buildSubtree(preorder, inorder_idx,
                         {p.start + 1 + left_size, p.end}, {mid + 1, i.end});

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty() ||
            preorder.size() != inorder.size())
            return nullptr;

        // Pre-index inorder vals to reduce lookups to O(1) -> O(N) for overall
        // runtime
        std::unordered_map<int, size_t> inorder_idx;
        inorder_idx.reserve(inorder.size());

        for (size_t idx = 0; idx < inorder.size(); ++idx) {
            inorder_idx[inorder[idx]] = idx;
        }

        return buildSubtree(preorder, inorder_idx, {0, preorder.size()},
                            {0, inorder.size()});
    }
};
