class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> ans, keys = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        queue<string> que;
        for(char it : keys[digits[0] - '0']) que.push({it});
        while(!que.empty()) {
            string it0 = que.front();
            que.pop();
            if(it0.size() == digits.size()) {
                ans.push_back(it0);
                continue;
            }
            for(auto it1 : keys[digits[it0.size()] - '0']) {
                que.push(it0 + string(1, it1));
            }
        }
        return ans;
    }
};