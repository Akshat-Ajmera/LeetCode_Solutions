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
    int maxLevelSum(TreeNode* root) {
        int ans = 0, lvl = 0, lvlTot, tot = INT_MIN, siz;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            siz = que.size();
            lvlTot = 0;
            lvl++;
            while(siz--) {
                auto node = que.front();
                que.pop();
                lvlTot += node -> val;
                if(node -> left) que.push(node -> left);
                if(node -> right) que.push(node -> right);
            }
            if(lvlTot > tot) {
                ans = lvl;
                tot = lvlTot;
            }
        }
        return ans;
    }
};