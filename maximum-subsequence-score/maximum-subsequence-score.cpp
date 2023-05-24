class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int K) {
        int n = nums1.size();
        vector<pair<int, int>> v(n);
        for(int i=0; i<n; i++) {
            v[i] = {nums2[i], nums1[i]};
        }
        sort(v.rbegin(), v.rend());
        long long currsum = 0, bestsum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int j=0; j<n; j++) {
            currsum += v[j].second;
            pq.push(v[j].second);
            if(pq.size()>K) {
                int m = pq.top();
                pq.pop();
                currsum -= m;
            }
            if(pq.size()==K) {
                bestsum = max(bestsum, currsum*v[j].first);
            }
        }
        return bestsum;
    }
};  