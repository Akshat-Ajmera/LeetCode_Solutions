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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int x,y;
        TreeNode* node;
        vector<vector<int>> ans;
        if(!root) {
            return ans;
        }
        map<int,map<int,multiset<int>>> order;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            node = it.first;
            x = it.second.first;
            y = it.second.second;
            if(node->left) {
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right) {
                q.push({node->right,{x+1,y+1}});
            }
            // order.insert({x,{y,node->val}});
            order[x][y].insert(node->val);
        }
        for(auto X : order) {
            vector<int> col;
            for(auto Y : X.second) {
                for(auto it1=Y.second.begin(); it1!=Y.second.end(); it1++) {
                    col.push_back(*it1);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};