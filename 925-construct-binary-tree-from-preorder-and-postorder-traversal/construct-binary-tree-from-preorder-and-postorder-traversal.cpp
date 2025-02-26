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
    TreeNode* builder(int &preIndex, int &postIndex, vector<int> &preorder, vector<int> &postorder) {
        TreeNode* root = new TreeNode(preorder[preIndex]);
        preIndex++;
        if(root->val != postorder[postIndex]) root->left = builder(preIndex, postIndex, preorder, postorder);
        if(root->val != postorder[postIndex]) root->right = builder(preIndex, postIndex, preorder, postorder);
        postIndex++;
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preIndex = 0, postIndex = 0;
        return builder(preIndex, postIndex, preorder, postorder);
    }
};