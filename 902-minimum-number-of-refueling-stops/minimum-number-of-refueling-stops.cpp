class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size(), cnt = 0, idx = 0, farthest = 0;
        priority_queue<int> pq;
        pq.push(startFuel);
        while(!pq.empty() && farthest < target) {
            auto it = pq.top();
            pq.pop();
            farthest += it;
            if(farthest >= target) return cnt;
            cnt++;
            while(idx < n && stations[idx][0] <= farthest) {
                pq.push(stations[idx][1]);
                idx++;
            }
        }
        return -1;
    }
};