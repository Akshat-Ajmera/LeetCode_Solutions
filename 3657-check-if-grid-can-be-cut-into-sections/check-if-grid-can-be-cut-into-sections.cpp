class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int cnt = 0, lines= 0;
        vector<pair<int, int>> hor, ver;
        for(auto &it : rectangles) {
            hor.push_back({it[0], 1});
            ver.push_back({it[1], 1});
            hor.push_back({it[2], 0});
            ver.push_back({it[3], 0});
        }
        sort(hor.begin(), hor.end());
        for(int i=0; i<hor.size(); i++) {
            if(hor[i].second) cnt++;
            else cnt--;
            if(!cnt) lines++;
        }
        if(lines >= 3) return true;
        lines = 0;
        sort(ver.begin(), ver.end());
        for(int i=0; i<ver.size(); i++) {
            if(ver[i].second) cnt++;
            else cnt--;
            if(!cnt) lines++;
        }
        if(lines >= 3) return true;
        return false; 
    }
};