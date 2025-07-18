class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        long long ans = LLONG_MAX;
        vector<long long> minSum(3*n, 0), maxSum(3*n, 0);
        priority_queue<int> maxPQ;
        priority_queue<int, vector<int>, greater<int>> minPQ;
        minSum[0] = nums[0];
        maxPQ.push(nums[0]);
        for(int i=1; i<2*n; i++) {
            if(maxPQ.size() < n) {
                minSum[i] = nums[i] + minSum[i-1];
                maxPQ.push(nums[i]);
            }
            else {
                if(nums[i] < maxPQ.top()) {
                    minSum[i] = minSum[i-1] + nums[i] - maxPQ.top();
                    maxPQ.pop();
                    maxPQ.push(nums[i]);
                }
                else minSum[i] = minSum[i-1];
            }
        }
        maxSum[3*n-1] = nums[3*n-1];
        minPQ.push(nums[3*n-1]);
        for(int i=3*n-2; i>=n; i--) {
            if(minPQ.size() < n) {
                maxSum[i] = nums[i] + maxSum[i+1];
                minPQ.push(nums[i]);
            }
            else {
                if(nums[i] > minPQ.top()) {
                    maxSum[i] = maxSum[i+1] + nums[i] - minPQ.top();
                    minPQ.pop();
                    minPQ.push(nums[i]);
                }
                else maxSum[i] = maxSum[i+1];
            }
        }
        for(int i=n-1; i<2*n; i++) ans = min(ans, minSum[i] - maxSum[i+1]);
        return ans;
    }
};