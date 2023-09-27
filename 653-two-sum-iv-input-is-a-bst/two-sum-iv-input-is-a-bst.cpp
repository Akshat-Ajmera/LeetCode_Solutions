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
    void inTrav(TreeNode* root, vector<int> &v) {
        if(root->left) {
            inTrav(root->left,v);
        }
        v.push_back(root->val);
        if(root->right) {
            inTrav(root->right,v);
        }
    }
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) {
            return false;
        }
        vector<int> v;
        inTrav(root,v);
        int i=0, j=v.size()-1;
        while(i<j) {
            if(v[i]+v[j]==k) {
                return true;
            }
            else if(v[i]+v[j]<k) {
                i++;
            }
            else {
                j--;
            }
        }
        return false;
    }
};