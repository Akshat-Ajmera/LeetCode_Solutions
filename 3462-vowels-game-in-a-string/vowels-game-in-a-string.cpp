class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        set<char> st = {'a', 'e', 'i', 'o', 'u'};
        for(auto ch : s) {
            if(st.count(ch)) cnt++;
        }
        if(!cnt) return false;
        return true;
    }
};