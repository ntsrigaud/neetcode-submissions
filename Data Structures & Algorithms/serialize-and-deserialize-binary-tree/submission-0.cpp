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

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::ostringstream out;

        auto buildString = [&](auto& self, TreeNode* node) -> void {
            if (!node) {
                out << "N ";
                return;
            }

            // PreOrder DFS
            out << node->val << " ";
            self(self, node->left);
            self(self, node->right);
        };

        buildString(buildString, root);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::istringstream in(data);

        auto buildTree = [&](auto& self) -> TreeNode* {
            std::string val;
            if (!(in >> val) || val == "N") return nullptr;

            // PreOrder DFS
            auto* node = new TreeNode(std::stoi(val));
            node->left = self(self);
            node->right = self(self);

            return node;
        };

        return buildTree(buildTree);
    }
};
