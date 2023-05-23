class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int a=0; a<nums.size(); a++){
            pq.push(nums[a]);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};