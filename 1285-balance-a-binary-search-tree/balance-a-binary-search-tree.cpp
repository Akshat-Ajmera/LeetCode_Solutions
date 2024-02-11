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
    void inorderTraversal(TreeNode* root, vector<int> &in) {
        if(root->left) {
            inorderTraversal(root->left, in);
        }
        in.push_back(root->val);
        if(root->right) {
            inorderTraversal(root->right, in);
        }
    }
    TreeNode* buildBST(vector<int> &in, int lo, int hi) {
        int mid = (lo+hi)/2;
        TreeNode* root = new TreeNode(in[mid]);
        if(mid-1 >= lo) {
            root->left = buildBST(in, lo, mid-1);
        }
        if(mid+1 <= hi) {
            root->right = buildBST(in, mid+1, hi);
        }
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorderTraversal(root, in);
        return buildBST(in, 0, in.size()-1);
    }
};