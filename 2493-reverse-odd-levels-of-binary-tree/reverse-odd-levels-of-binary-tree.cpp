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
    void reverseVal(vector<TreeNode*> &v) {
        int n=v.size(), i=0, j=n-1;
        while(i<j) {
            int temp = v[i]->val;
            v[i]->val = v[j]->val;
            v[j]->val = temp;
            i++;
            j--;
        }
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) {
            return root;
        }
        int cnt = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int siz = que.size();
            if((cnt%2)) {
                vector<TreeNode*> v(siz);
                for(int i=0; i<siz; i++) {
                    TreeNode* node = que.front();
                    que.pop();
                    if(node->left) {
                        que.push(node->left);
                    }
                    if(node->right) {
                        que.push(node->right);
                    }
                    v[i] = node;
                }
                reverseVal(v);
            }
            else {
                for(int i=0; i<siz; i++) {
                    TreeNode* node = que.front();
                    que.pop();
                    if(node->left) {
                        que.push(node->left);
                    }
                    if(node->right) {
                        que.push(node->right);
                    }
                }
            }
            cnt++;
        }
        return root;
    }
};