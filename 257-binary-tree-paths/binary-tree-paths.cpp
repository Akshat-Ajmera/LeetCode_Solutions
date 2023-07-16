/*
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
    void pathFinder(TreeNode* root, vector<int>& path, vector<vector<int>>& paths) {
        if(!root) {
            return;
        }
        path.push_back(root->val);
        if(root->left) {
            pathFinder(root->left,path,paths);
        }
        if(root->right) {
            pathFinder(root->right,path,paths);
        }
        if(!root->left && !root->right) {
            paths.push_back(path);
            path.pop_back();
            return;
        }
        path.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) {
            return ans;
        }
        string s = "";
        vector<int> path;
        vector<vector<int>> paths;
        pathFinder(root,path,paths);
        int n=paths.size(), m;
        for(int i=0; i<n; i++) {
            m=paths[i].size();
            s += to_string(root->val);
            for(int j=1; j<m; j++) {
                s += "->" + to_string(paths[i][j]);
            }
            ans.push_back(s);
            s="";
        }
        return ans;
    }
};