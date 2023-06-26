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
public:
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int lDepth=0, rDepth=0;
        if(root->left) {
            lDepth = minDepth(root->left);
        }
        if(root->right) {
            rDepth = minDepth(root->right);
        }
        if(!lDepth && !rDepth) {
            return 1;
        }
        else if(!lDepth && rDepth) {
            return 1+rDepth;
        }
        else if(lDepth && !rDepth) {
            return 1+lDepth;
        }
        else {
            return 1+min(lDepth,rDepth);
        }
    }
};