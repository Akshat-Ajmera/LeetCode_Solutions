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
    int solve(TreeNode* root, int &ans) {
        if(!root) return 0;
        int leftSum = solve(root->left, ans);
        int rightSum = solve(root->right, ans);
        if(leftSum < 0) leftSum = 0;
        if(rightSum < 0) rightSum = 0;
        ans = max(ans, root->val + leftSum + rightSum);
        return root->val + max(leftSum, rightSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};