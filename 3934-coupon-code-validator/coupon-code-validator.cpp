class Solution {
private:    
    bool checkCode(string &code) {
        if(code == "") return false;
        for(char ch : code) {
            if(((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_')) continue;
            else return false;
        }
        return true;
    }
    bool checkBusinessLine(string &businessLine) {
        return (!((businessLine != "electronics") && (businessLine != "grocery") && (businessLine != "pharmacy") && (businessLine != "restaurant")));
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<string> ans;
        priority_queue<pair<string, string>, vector<pair<string, string>>, greater<pair<string, string>>> pq;
        for(int i=0; i<n; i++) {
            if(!checkCode(code[i]) || !checkBusinessLine(businessLine[i]) || !isActive[i]) continue;
            pq.push({businessLine[i], code[i]});
        }
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};