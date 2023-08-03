class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int siz = target.size();
        vector<int> v;
        string p1="Push", p2="Pop";
        for(int i=1; i<=n; i++) {
            v.push_back(i);
            ans.push_back(p1);
            if(v[v.size()-1] != target[v.size()-1]) {
                v.pop_back();
                ans.push_back(p2);
            }
            if(v.size()==siz) {
                return ans;
            }
        }
        return ans;
    }
};