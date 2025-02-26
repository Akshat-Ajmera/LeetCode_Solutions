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
class FindElements {
private:
    unordered_set<int> st;
    void treeBuilder(TreeNode* node, int value) {
        node->val = value;
        st.insert(value);
        if(node->left) treeBuilder(node->left, ((2*value)+1));
        if(node->right) treeBuilder(node->right, ((2*value)+2));
        return;
    }
public:
    FindElements(TreeNode* root) {
        treeBuilder(root, 0);
    }
    
    bool find(int target) {
        return (st.find(target) != st.end());
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */