class Solution {
private:
    int possible(vector<int> &v, int mxm) {
        int n = v.size(), currSum = 0, cnt = 1;
        for(int i=0; i<n; i++) {
            if(currSum + v[i] <= mxm) {
                currSum += v[i];
            }
            else {
                currSum = v[i];
                cnt++;
            }
        }
        return cnt;
    }
public:
    int splitArray(vector<int> &nums, int k) {
        int n = nums.size(), lo = 0, hi = 0, mid;
        for(auto &it : nums) {
            lo = max(lo, it);
            hi += it;
        }
        while(lo <= hi) {
            mid = (lo + ((hi - lo) / 2));
            if(possible(nums, mid) > k) lo = mid + 1;
            else hi = mid - 1;
        }
        return lo;
    }
};