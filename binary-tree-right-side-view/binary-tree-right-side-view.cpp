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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) {
            return ans;
        }
        vector<vector<int>> bfs;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int siz = q.size();
            vector<int> level;
            for(int i=0; i<siz; i++) {
                auto curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
            }
            bfs.push_back(level);
        }
        int sizBFS = bfs.size();
        ans.resize(sizBFS);
        for(int i=0; i<sizBFS; i++) {
            int sizLVL = bfs[i].size();
            ans[i] = bfs[i][sizLVL-1];
        }
        return ans;
    }
};