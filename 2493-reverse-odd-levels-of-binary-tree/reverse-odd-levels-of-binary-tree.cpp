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
    void reverse(TreeNode* r1,TreeNode* r2,int level) {
        if(!r1 || !r2) {
            return;
        }
        if(level%2) {
            swap(r1->val, r2->val);
        }
        reverse(r1->left, r2->right, level+1);
        reverse(r2->left, r1->right, level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        reverse(root->left, root->right, 1);
        return root;
    }
};