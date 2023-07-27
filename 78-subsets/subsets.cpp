class Solution {
private:
    void adder(vector<int> &v, vector<int> &u, int i, vector<vector<int>> &ans) {
        if(i>=v.size()) {
            ans.push_back(u);
            return;
        }
        u.push_back(v[i]);
        adder(v,u,i+1,ans);
        u.pop_back();
        adder(v,u,i+1,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size(), i=0;
        vector<int> u;
        vector<vector<int>> ans;
        adder(nums,u,0,ans);
        return ans;
    }
};