class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr[0] > k) return k;
        for(int i=0; i<arr.size(); i++) {
            if(k >= arr[i]) k++;
            else return k;
        }
        return k;
    }
};