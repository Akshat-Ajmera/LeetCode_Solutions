class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> pairs(n, 0);
        for(int i=0; i<n; i++) {
            int lo = 0, hi = m-1, mid;
            while(lo <= hi) {
                mid = lo + ((hi - lo) / 2);
                if(((long long)potions[mid] * (long long)spells[i]) < success) lo = mid + 1;
                else hi = mid - 1;
            }
            pairs[i] = m - lo;
        }
        return pairs;
    }
};