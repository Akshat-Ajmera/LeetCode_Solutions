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
    TreeNode* nodeFinder(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            auto node=q.front();
            q.pop();
            if(node->val==k) {
                return node;
            }
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }
        return NULL;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        int ans = -1, siz = 0;
        if(!root) {
            return ans+1;
        }
        TreeNode* curr = nodeFinder(root,start);
        queue<TreeNode*>q;
        unordered_map<TreeNode*,TreeNode*> mp;
        unordered_set<TreeNode*> st;
        q.push(root);
        while(!q.empty()) {
            auto it=q.front();
            q.pop();
            if(it->left) {
                q.push(it->left);
                mp[it->left] = it;
            }
            if(it->right) {
                q.push(it->right);
                mp[it->right] = it;
            }
        }
        q.push(curr);
        st.insert(curr);
        while(!q.empty()) {
            siz = q.size();
            while(siz--) {
                auto node=q.front();
                q.pop();
                if(node->left && !st.count(node->left)) {
                    st.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && !st.count(node->right)) {
                    st.insert(node->right);
                    q.push(node->right);
                }
                if(mp.count(node) && !st.count(mp[node])) {
                    st.insert(mp[node]);
                    q.push(mp[node]);
                }
            }
            ans++;
        }
        return ans;
    }
};