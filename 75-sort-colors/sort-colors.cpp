class Solution {
public:

// 0.........lo-1 0s
// lo........mid-1 1s
// mid.......hi unsorted elems
// hi+1......n 1s
    void sortColors(vector<int> &nums) {
        int lo = 0, mid = 0, hi = nums.size()-1;
        while(mid <= hi) {
            if(nums[mid] == 0) {
                swap(nums[lo], nums[mid]);
                lo++;
                mid++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[hi]);
                hi--;
            }
        }
        return;
    }
};