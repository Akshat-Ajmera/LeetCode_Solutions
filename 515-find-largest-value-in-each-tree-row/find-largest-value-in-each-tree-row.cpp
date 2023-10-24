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
    void levelOrderTraversal(TreeNode* root, vector<int> &ans) {
        queue<TreeNode*> q;
        int siz, mxm;
        q.push(root);
        while(!q.empty()) {
            siz = q.size();
            mxm = INT_MIN;
            while(siz--) {
                auto it = q.front();
                q.pop();
                if(it->left) {
                    q.push(it->left);
                }
                if(it->right) {
                    q.push(it->right);
                }
                mxm = max(mxm, it->val);
            }
            ans.push_back(mxm);
        }
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root) {
            return ans;
        }
        levelOrderTraversal(root,ans);
        return ans;
    }
};