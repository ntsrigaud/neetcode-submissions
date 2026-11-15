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
    static constexpr char NULL_REF = 'N';
    static constexpr char SEP = ',';

    void encode(const TreeNode* root, std::string& out) const {
        if (!root) {
            out.push_back(NULL_REF);
            out.push_back(SEP);
            return;
        }

        out += std::to_string(root->val);
        out.push_back(SEP);

        encode(root->left, out);
        encode(root->right, out);
    }

    // Use mutable cursor index over str and parse integers in-place
    TreeNode* decode(std::string_view data, size_t& pos) const {
        if (pos >= data.size()) return nullptr;

        if (data[pos] == NULL_REF) {
            ++pos;                                              // Skip 'N'
            if (pos <= data.size() && data[pos] == SEP) ++pos;  // Skip ','
            return nullptr;
        }

        // Handle negative values & parse integers in-place
        int val = 0;
        const auto [ptr, ec] = std::from_chars(data.data() + pos, data.data() + data.size(), val);

        pos = static_cast<size_t>(ptr - data.data());
        if (pos < data.size() && data[pos] == SEP) ++pos;  // Skip ','

        // Reconstruct in matching preorder sequence
        TreeNode* root = new TreeNode(val);
        root->left = decode(data, pos);
        root->right = decode(data, pos);

        return root;
    }

   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string result;
        encode(root, result);

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        size_t pos = 0;
        return decode(data, pos);
    }
};
