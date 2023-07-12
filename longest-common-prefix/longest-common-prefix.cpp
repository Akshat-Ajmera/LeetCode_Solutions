class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1) {
            return strs[0];
        }
        sort(strs.begin(),strs.end());
        string s="", s1=strs[0], s2=strs[strs.size()-1];
        int n1=s1.size(), n2=s2.size(), i=0;
        while(i<min(n1,n2) && s1[i]==s2[i]) {
            s += s1[i];
            i++;
        }
        return s;
    }
};