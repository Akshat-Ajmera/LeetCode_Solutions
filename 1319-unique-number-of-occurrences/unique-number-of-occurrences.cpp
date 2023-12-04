class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        map<int,int> mp;
        set<int> st;
        for(int i=0; i<n; i++) {
            mp[arr[i]]++;
        }
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(!st.count(it->second)) {
                st.insert(it->second);
            }
            else {
                return false;
            }
        }
        return true;
    }
};