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
    void solve(TreeNode* node, vector<int> temp, vector<vector<int>> &paths) {
        temp.push_back(node->val);
        if(!node->left && !node->right) {
            paths.push_back(temp);
        }
        if(node->left) solve(node->left, temp, paths);
        if(node->right) solve(node->right, temp, paths);
        temp.pop_back();
        return;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> paths;
        vector<int> temp;
        solve(root, temp, paths);
        vector<string> ans(paths.size());
        for(int i=0; i<ans.size(); i++) {
            for(int j=0; j<paths[i].size(); j++) {
                ans[i] += to_string(paths[i][j]);
                ans[i] += "->";
            }
            ans[i].pop_back();
            ans[i].pop_back();
        }
        return ans;
    }
};