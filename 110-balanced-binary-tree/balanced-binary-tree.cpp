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
    int solve(TreeNode* root) {
        if(!root) return 0;
        int leftHt = solve(root->left);
        int rightHt = solve(root->right);
        if(leftHt == -1 || rightHt == -1 || abs(leftHt - rightHt) > 1) return -1;
        return 1 + max(leftHt, rightHt);
    }
public:
    bool isBalanced(TreeNode* root) {
        return (solve(root) != -1);
    }
};