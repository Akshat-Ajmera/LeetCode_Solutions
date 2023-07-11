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
    int maxDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
    int DiaCalc(TreeNode* root, int &res) {
        if(!root) {
            return 0;
        }
        res = max(res,maxDepth(root->left)+maxDepth(root->right));
        DiaCalc(root->left, res);
        DiaCalc(root->right, res);
        return res;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = -1;
        if(!root) {
            return ans;
        }
        DiaCalc(root,ans);
        return ans;
    }
};