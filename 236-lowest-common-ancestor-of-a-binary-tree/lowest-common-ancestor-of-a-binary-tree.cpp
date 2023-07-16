/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void pathFinder(TreeNode* root, TreeNode* a, vector<TreeNode*>& path) {
        if(!root) {
            return;
        }
        if(!path.empty()) {
            if(path[path.size()-1]->val==a->val) {
                return;
            }
        }
        path.push_back(root);
        if(root==a) {
            return;
        }
        pathFinder(root->left,a,path);
        pathFinder(root->right,a,path);
        if(!root->left && !root->right && !path.empty()) {
            path.pop_back();
            return;
        }
        if(!path.empty() && path[path.size()-1]!=a) {
            path.pop_back();
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) {
            return root;
        }
        vector<TreeNode*> pPath, qPath;
        pathFinder(root,p,pPath);
        pathFinder(root,q,qPath);
        int i=0;
        while(i<min(pPath.size(),qPath.size()) && pPath[i]==qPath[i]) {
            i++;
        }
        return pPath[i-1];
    }
};