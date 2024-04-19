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
    void solve(TreeNode* root, int num, vector<int> &v) {
        if(!root->left && !root->right) v.push_back((num * 10) + root->val);
        int ans1 = 0, ans2 = 0;
        if(root->left) solve(root->left, (num * 10) + root->val, v);
        if(root->right) solve(root->right, (num * 10) + root->val, v);
        return;
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<int> v;
        int ans = 0;
        solve(root, 0, v);
        for(auto it : v) ans += it;
        return ans;
    }
};