class Solution {
private:
    int kadaneAlgo(vector<int> &v) {
        int n = v.size(), currSum = 0, maxSum = 0;
        for(int i=0; i<n; i++) {
            currSum += v[i];
            maxSum = max(maxSum, currSum);
            if(currSum < 0) currSum = 0;
        }
        return maxSum;
    } 
public:
    int maxAbsoluteSum(vector<int>& v) {
        int a, b;
        a = kadaneAlgo(v);
        for(auto &it : v) it *= -1;
        b = kadaneAlgo(v);
        return max(a, b);
    }
};
