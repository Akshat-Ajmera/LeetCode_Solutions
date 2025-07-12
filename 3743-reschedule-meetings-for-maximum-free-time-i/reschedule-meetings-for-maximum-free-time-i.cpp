class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& beginTime, vector<int>& endTime) {
        int n = beginTime.size(), time = beginTime[0], beginPtr = 0, endPtr = 1, ans = 0, i = 1;
        beginTime.push_back(eventTime);
        while(i <= k) {
            time += (beginTime[i] - endTime[i-1]);
            endPtr = i;
            i++;
        }
        if(k == n) return time;
        ans = time;
        time = time - beginTime[0] + beginTime[i] - endTime[i-1];
        i++;
        beginPtr++;
        endPtr = i;
        ans = max(ans, time);
        for(i; i<=n; i++) {
            time = time - (beginTime[beginPtr] - endTime[beginPtr-1]) + (beginTime[endPtr] - endTime[endPtr-1]);
            ans = max(ans, time);
            beginPtr++;
            endPtr++;
        }
        return ans;
    }
};