class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int cnt = 1;
        unordered_set<string> st;
        for(string &str : wordList) st.insert(str);
        st.insert(beginWord);
        queue<string> que;
        que.push(beginWord);
        while(!que.empty()) {
            int siz = que.size();
            while(siz--) {
                string word = que.front();
                que.pop();
                string word1 = word;
                for(int i=0; i<word1.size(); i++) {
                    word1 = word;
                    for(char ch='a'; ch<='z'; ch++) {
                        word1[i] = ch;
                        if((word1 == word) || (!st.count(word1))) continue;
                        if(word1 == endWord) return cnt + 1;
                        que.push({word1});
                    }
                }
                st.erase(word);
            }
            cnt++;
        }
        return 0;
    }
};