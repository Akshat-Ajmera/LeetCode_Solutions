class Solution {
public:
    long long coloredCells(int n) {
        return (long long)(1+(4*(((long long)n*((long long)n-1))/2)));
    }
};