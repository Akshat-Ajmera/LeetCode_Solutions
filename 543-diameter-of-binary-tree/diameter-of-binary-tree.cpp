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
    int height(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    int solve(TreeNode* root, int &ans) {
        if(!root) return 0;
        int leftHt = height(root->left);
        int rightHt = height(root->right);
        ans = max(ans, leftHt + rightHt);
        solve(root->left, ans);
        solve(root->right, ans);
        return max(leftHt, rightHt);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};