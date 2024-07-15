class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(), lo = 0, hi = n-1, mid, i, j;
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0; i<n; i++) pq.push({abs(arr[i] - x), arr[i]});
        while(k--) {
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};