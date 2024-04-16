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
private:
    void solve(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* node1 = new TreeNode(val);
            TreeNode* node2 = new TreeNode(val);
            if(root->left) {
                TreeNode* temp;
                temp = root->left; 
                root->left = node1;
                node1->left = temp;
            }
            else {
                root->left = node1;
            }
            if(root->right) {
                TreeNode* temp;
                temp = root->right;
                root->right = node2;
                node2->right = temp;
            }
            else {
                root->right = node2;
            }
            return;
        }
        if(root->left) solve(root->left, val, depth-1);
        if(root->right) solve(root->right, val, depth-1);
        return;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        solve(root, val, depth-1);
        return root;
    }
};