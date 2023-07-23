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
    int lHeight(TreeNode* root, int &h) {
        if(!root) {
            return h;
        }
        h++;
        return lHeight(root->left, h);
    }
    int rHeight(TreeNode* root, int &h) {
        if(!root) {
            return h;
        }
        h++;
        return rHeight(root->right, h);
    }
    int nodeCalc(TreeNode* root, int &cnt) {
        if(!root) {
            return 0;
        }
        int lh = 0, rh = 0;
        lHeight(root, lh);
        rHeight(root, rh);
        if(lh == rh) {
            cnt = pow(2,lh)-1;
            return cnt;
        }
        return nodeCalc(root->left, cnt) + nodeCalc(root->right, cnt) + 1;
    }
public:
    int countNodes(TreeNode* root) {
        int ans = 0;
        return nodeCalc(root, ans);
    }
};