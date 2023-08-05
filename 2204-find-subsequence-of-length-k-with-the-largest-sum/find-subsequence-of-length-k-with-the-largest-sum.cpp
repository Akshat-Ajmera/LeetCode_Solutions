class Solution {
private:
    static bool comp(pair<int,int> &a, pair<int,int> &b) {
        return a.second < b.second;
    }
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        vector<pair<int,int>> v(k);
        vector<int> ans(k);
        for(int i=0; i<n; i++) {
            pq.push({nums[i],i});
        }
        for(int i=0; i<k; i++) {
            auto it = pq.top();
            pq.pop();
            v[i].first = it.first;
            v[i].second = it.second;
        }
        sort(v.begin(),v.end(),comp);
        for(int i=0; i<k; i++) {
            ans[i] = v[i].first;
        }
        return ans;
    }
};