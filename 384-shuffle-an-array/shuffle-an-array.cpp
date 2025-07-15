class Solution {
private:
    vector<int> unshuffled, shuffled;
public:
    Solution(vector<int>& nums) {
        shuffled = nums;
        unshuffled = nums;
    }
    vector<int> reset() {
        return unshuffled;
    }
    vector<int> shuffle() {
        int n = shuffled.size(), ind;
        for(int i=0; i<n; i++) {
            ind = rand() % n;
            swap(shuffled[i], shuffled[ind]);
        }
        return shuffled;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */