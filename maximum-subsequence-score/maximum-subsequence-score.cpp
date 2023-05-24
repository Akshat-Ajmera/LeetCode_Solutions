class Solution {
 public:
  // Same as 1383. Maximum Performance of a Team
  long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    long long ans = 0;
    long long sum = 0;
    // (nums2[i], nums1[i]) sorted by nums2[i] in descending order.
    vector<pair<int, int>> A;
    priority_queue<int, vector<int>, greater<>> minHeap;

    for (int i = 0; i < nums1.size(); ++i)
      A.emplace_back(nums2[i], nums1[i]);

    sort(begin(A), end(A), greater<>());

    for (const auto& [num2, num1] : A) {
      minHeap.push(num1);
      sum += num1;
      if (minHeap.size() > k)
        sum -= minHeap.top(), minHeap.pop();
      if (minHeap.size() == k)
        ans = max(ans, sum * num2);
    }

    return ans;
  }
};
// class Solution {
// public:
//     long long maxScore(vector<int>& nums1, vector<int>& nums2, int K) {
//         int n = nums1.size();
//         vector<pair<int, int>> v(n);
//         for(int i=0; i<n; i++) {
//             v[i].first = nums2[i];
//             v[i].second = nums1[i];
//         }
//         sort(v.begin(), v.end());
//         for(auto it : v) {
//             cout << it.first << "\t" << it.second << endl;
//         }
//         long long currsum = 0, bestsum = 0;
//         for(int j=0; j<n-K+1; j++) {
//             int t = v[j].first;
//             currsum += v[j].second;
//             priority_queue<int, vector<int>, greater<int>> pq;
//             for(int k=j+1; k<n-1; k++) {
//                 pq.push(v[k].second);
//                 currsum += v[k].second;
//                 if(pq.size()>K-1) {
//                     int it = pq.top();
//                     currsum -= it;
//                     pq.pop();
//                 }
//             }
//             currsum *= t;
//             cout << "currsum " << j << "  " << currsum << endl;
//             if(currsum>bestsum) {
//                 bestsum = currsum;
//             }
//             currsum = 0;
//         }
//         return bestsum;
//     }
// };  