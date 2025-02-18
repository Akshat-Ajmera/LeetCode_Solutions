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
    int solve(TreeNode* node, bool taken, map<pair<TreeNode*, bool>, int> &mp) {
        if(!node) return 0;
        if(mp.find({node, taken}) != mp.end()) return mp[{node, taken}];
        int a = solve(node->left, !taken, mp) + solve(node->right, !taken, mp);
        int b = solve(node->left, taken, mp) + solve(node->right, !taken, mp);
        int c = solve(node->left, !taken, mp) + solve(node->right, taken, mp);
        int d = solve(node->left, taken, mp) + solve(node->right, taken, mp);
        if(taken) return mp[{node, taken}] = (node->val + a);
        else return mp[{node, taken}] = max({a, b, c, d});
    }
public:
    int rob(TreeNode* root) {
        map<pair<TreeNode*, bool>, int> mp;
        return max(solve(root, true, mp), solve(root, false, mp));
    }
};