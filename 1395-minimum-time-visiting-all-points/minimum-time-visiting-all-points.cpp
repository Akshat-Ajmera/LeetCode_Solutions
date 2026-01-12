class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& pts) {
        int ans = 0, x, y;
        for(int i=0; i<pts.size()-1; i++) {
            x = abs(pts[i+1][0] - pts[i][0]), y = abs(pts[i+1][1] - pts[i][1]);
            ans += max(x, y);
        }
        return ans;
    }
};