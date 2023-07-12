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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        double sum=0;
        int siz=0;
        if(!root) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            siz = q.size();
            for(int i=0; i<siz; i++) {
                TreeNode* it=q.front();
                q.pop();
                sum += (it->val);
                if(it->left) {
                    q.push(it->left);
                }
                if(it->right) {
                    q.push(it->right);
                }
            }
            ans.push_back(sum/siz);
            sum=0;
        }
        return ans;
    }
};