class Solution {
private:
    static bool comp(const pair<int, int> &a, const pair<int, int> &b) {
        if(a.first != b.first) return a.first < b.first;
        else return a.second > b.second;
    }
public:
    int findMaximizedCapital(int k, int w, vector<int>& pft, vector<int>& cap) {
        int n = pft.size(), ans = w, j = 0;
        vector<pair<int, int>> v(n);
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<n; i++) {
            v[i].first = cap[i];
            v[i].second = pft[i];
        }
        sort(v.begin(), v.end(), comp);
        while(k--) {
            while(j < n && v[j].first <= ans) {
                pq.push({v[j].second, v[j].first});
                j++;
            }
            if(!pq.empty()) {
                auto it = pq.top();
                pq.pop();
                ans += it.first;
            }
        }
        return ans;
    }
};