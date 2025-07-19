class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        string last;
        sort(folder.begin(), folder.end());
        ans.push_back(folder[0]);
        for(int i=1; i<folder.size(); i++) {
            last = ans.back();
            last += '/';
            if(folder[i].compare(0, last.size(), last)) ans.push_back(folder[i]);
        }
        return ans;
    }
};