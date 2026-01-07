class Solution {
private:
    long long dfs(TreeNode* node) {
        if (!node) return 0;
        node -> val += dfs(node -> left) + dfs(node -> right);
        return node -> val;
    }
public:
    int maxProduct(TreeNode* root) {
        long long tot = dfs(root), cur, ans = 0, mod = 1e9 + 7;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            if (!node) continue;
            cur = (tot - node -> val) * node -> val;
            ans = max(ans, cur);
            if (node -> left) que.push(node -> left);
            if (node -> right) que.push(node -> right);
        }
        return ans % mod;
    }
};