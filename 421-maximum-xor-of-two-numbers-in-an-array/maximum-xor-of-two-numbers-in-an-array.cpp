struct TrieNode {
    TrieNode* lists[2];
    bool containsKey(int i) {return lists[i] != NULL;}
    TrieNode* get(int i) {return lists[i];}
    void set(int i, TrieNode* node) {lists[i] = node;}
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(int num) {
        TrieNode* curr = root;
        for(int i=31; i>=0; i--) {
            bool x = num & (1 << i);
            if(!(curr->containsKey(x))) curr->set(x, new TrieNode());
            curr = curr->get(x);
        }
        return;
    }
    int zor(int num) {
        TrieNode* curr = root;
        int ans = 0;
        for(int i=31; i>=0; i--) {
            bool x = num & (1 << i);
            if(curr->containsKey(!x)) {
                ans += (1 << i);
                curr = curr->get(!x);
            }
            else {
                curr = curr->get(x);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        int ans = 0;
        Trie* obj = new Trie();
        for(auto &it : nums) obj->insert(it);
        for(auto &it : nums) ans = max(ans, obj->zor(it));
        return ans;
    }
};