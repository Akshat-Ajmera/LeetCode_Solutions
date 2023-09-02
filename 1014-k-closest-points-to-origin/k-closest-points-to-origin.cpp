class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        int n = points.size(), dis = 0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> ans(k, vector<int> (2));
        for(int i=0; i<n; i++) {
            dis = (points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            pq.push({dis,{points[i][0],points[i][1]}}); 
        }
        for(int i=0; i<k; i++) {
            auto it = pq.top();
            pq.pop();
            ans[i][0] = it.second.first;
            ans[i][1] = it.second.second;
        }
        return ans;
    }
};