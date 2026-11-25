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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(key > root->val){
            root->right = deleteNode(root->right,key);
        }else if(key < root->val){
            root->left = deleteNode(root->left,key);
        }
        else{
            //No left child
            if(root->left==NULL) return root->right;
            //No right child
            if(root->right==NULL) return root->left;
            //Two childrens
            TreeNode* successor = root->right;
            while(successor->left != nullptr){
                successor = successor->left;
            }
            root->val = successor->val;
            root->right = deleteNode(root->right,successor->val);
        }
        return root;
    }
};