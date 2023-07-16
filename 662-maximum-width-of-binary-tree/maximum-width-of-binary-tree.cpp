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
public:
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long ans=0;
        if(!root) {
            return ans;
        }
        queue<pair<TreeNode*,int>> q;
        ans=1;
        q.push({root,ans});
        while(!q.empty()) {
            int siz=q.size();
            vector<unsigned long long> level;
            for(int i=0; i<siz; i++) {
                auto it=q.front();
                q.pop();
                TreeNode* curr=it.first;
                unsigned long long pt=it.second;
                if(curr->left) {
                    level.push_back(2*pt);
                    q.push({curr->left,2*pt});
                }
                if(curr->right) {
                    level.push_back(2*pt+1);
                    q.push({curr->right,2*pt+1});
                } 
            }
            if(!level.empty()) { 
                ans = max(ans,level[level.size()-1]-level[0]+1);
            }
        }
        return ans;
    }
};