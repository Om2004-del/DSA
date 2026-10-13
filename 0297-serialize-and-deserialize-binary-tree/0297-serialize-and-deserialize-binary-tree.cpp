/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Serialize
    void preorder(TreeNode* root, string &ans) {
        if (root == nullptr) {
            ans += "N,";
            return;
        }

        ans += to_string(root->val) + ",";

        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    string serialize(TreeNode* root) {
        string ans;
        preorder(root, ans);
        return ans;
    }

    // Deserialize
    TreeNode* build(vector<string>& nodes, int &index) {
        if (nodes[index] == "N") {
            index++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[index]));
        index++;

        root->left = build(nodes, index);
        root->right = build(nodes, index);

        return root;
    }

    TreeNode* deserialize(string data) {

        vector<string> nodes;
        string temp;

        for (char ch : data) {
            if (ch == ',') {
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }

        int index = 0;

        return build(nodes, index);
    }
};

/**
 * Your Codec object will be instantiated and called as such:
 * Codec ser, deser;
 * TreeNode* ans = deser.deserialize(ser.serialize(root));
 */