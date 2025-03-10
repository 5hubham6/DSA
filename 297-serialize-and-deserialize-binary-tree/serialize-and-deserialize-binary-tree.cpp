/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        if (!root) return "null,";
        return std::to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes a single string to a binary tree.
    TreeNode* deserialize(std::string data) {
        std::stringstream ss(data);
        std::string token;
        std::queue<std::string> q;
        while (getline(ss, token, ',')) {
            q.push(token);
        }
        return deserializeHelper(q);
    }

private:
    TreeNode* deserializeHelper(std::queue<std::string>& q) {
        std::string s = q.front();
        q.pop();
        if (s == "null") return nullptr;
        TreeNode* root = new TreeNode(stoi(s));
        root->left = deserializeHelper(q);
        root->right = deserializeHelper(q);
        return root;
    }
};