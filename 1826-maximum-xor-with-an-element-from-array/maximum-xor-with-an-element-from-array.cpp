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
private:
    static bool comp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
        return (a.second.second < b.second.second);
    }
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
        int n = queries.size(), m = nums.size(), val, x;
        vector<pair<int, pair<int, int>>> v(n);
        vector<int> ans(n, -1);
        for(int i=0; i<n; i++) {
            v[i] = {i, {queries[i][0], queries[i][1]}};
        }
        sort(nums.begin(), nums.end());
        sort(v.begin(), v.end(), comp);
        Trie* obj = new Trie();
        int idx = 0;
        for(int i=0; i<n; i++) {
            x = v[i].second.first;
            val = v[i].second.second;
            if(nums[0] > val) continue;
            for(int j=idx; j<m && nums[j]<=v[i].second.second; j++) {
                obj->insert(nums[j]);
                idx++;
            }
            ans[v[i].first] = obj->zor(x);
        }
        return ans;
    }
};