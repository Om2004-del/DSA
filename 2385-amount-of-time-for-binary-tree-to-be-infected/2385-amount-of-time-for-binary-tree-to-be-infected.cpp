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
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;

        q.push(root);
        TreeNode* target = nullptr;
        parent[root] = nullptr;

        // Build parent map and find start node
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->val == start)
                target = node;

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        // Start infection from target
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);

        int time = -1;

        while (!q.empty()) {
            int n = q.size();
            time++;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left &&
                    !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }

                if (node->right &&
                    !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }

                TreeNode* p = parent[node];

                if (p && !visited.count(p)) {
                    visited.insert(p);
                    q.push(p);
                }
            }
        }

        return time;
    }
};
