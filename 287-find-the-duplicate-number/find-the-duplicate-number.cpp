class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), z=0;
        vector<int> adj[n+1];
        while(true) {
            adj[z].push_back(nums[z]);
            // adj[nums[z]].push_back(z);
            if(adj[z].size() > 1) {
                return z;
            }
            z = nums[z];
        }
        return -1;
    }
};