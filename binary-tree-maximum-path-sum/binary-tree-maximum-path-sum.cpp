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
    int calcSum(TreeNode* root, int &ans) {
        if(!root) {
            return 0;
        }
        int lSum=calcSum(root->left,ans), rSum=calcSum(root->right,ans), data=root->val;
        ans = max({ans,data+lSum+rSum,data,data+lSum,data+rSum});
        return max(data,data+max(lSum,rSum));
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int ans = INT_MIN;
        calcSum(root,ans);
        return ans;
    }
};