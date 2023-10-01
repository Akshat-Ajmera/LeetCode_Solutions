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
    TreeNode* pichla;
    TreeNode* pehla;
    TreeNode* dusra;
    void inorderTraversal(TreeNode* root) {
        if(!root) {
            return;
        }
        inorderTraversal(root->left);
        if(pichla && pichla->val > root->val) {
            if(!pehla) {
                pehla = pichla;
            }
            dusra = root;
        }
        pichla = root;
        inorderTraversal(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        pichla=NULL, pehla=NULL, dusra=NULL;
        inorderTraversal(root);
        int temp = pehla->val;
            pehla->val = dusra->val;
            dusra->val = temp;
            return;
    }
};