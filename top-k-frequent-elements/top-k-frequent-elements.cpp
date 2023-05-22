class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for(int i=0; i<nums.size(); i++) {
            um[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto i : um) {
            pq.push({i.second, i.first});
        }
        vector<int> v;
        while(k--) {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return  v;
    }
};