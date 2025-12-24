class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
        int tot = 0, ans = 0;
        for(int it : apple) tot += it;
        for(int it : capacity) {
            tot -= it;
            ans++;
            if(tot <= 0) break; 
        }
        return ans;
    }
};