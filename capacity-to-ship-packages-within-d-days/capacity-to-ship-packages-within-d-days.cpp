class Solution {
private:
    int daysReq(vector<int>& w, int cap) {
        int days=0, n=w.size(), wt=0;
        for(int i=0; i<n; i++) {
            wt += w[i];
            if(wt>cap) {
                wt=w[i];
                days++;
            }
        }
        if(wt>0) { 
            days++;
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& w, int days) {
        int n=w.size(), mn=*max_element(w.begin(),w.end()), mx=accumulate(w.begin(),w.end(),0);
        while(mn<=mx) {
            int mid=(mn+mx)/2, totalDays=daysReq(w,mid);
            if(days<totalDays) {
                mn = mid+1;
            }
            else if(days>=totalDays) {
                mx = mid-1;
            }
        }
        return mn;
    }
};