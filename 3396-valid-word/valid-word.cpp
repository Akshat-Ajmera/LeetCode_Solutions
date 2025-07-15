class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        unordered_set<char> st, vowel, wordSet;
        for(char i='0'; i<='9'; i++) st.insert(i);
        for(char i='a'; i<='z'; i++) st.insert(i);
        for(char i='A'; i<='Z'; i++) st.insert(i);
        for(char ch : word) if(st.find(ch) == st.end()) return false;
        vowel.insert({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        int cnt = 0;
        for(char ch : word) if(vowel.count(ch)) cnt++;
        if(!cnt) return false;
        wordSet.insert(word.begin(), word.end());
        cnt = 0;
        for(char c='a'; c<='z'; c++) {
            if(vowel.count(c)) continue;
            if(wordSet.count(c)) cnt++;
        }
        for(char c='A'; c<='Z'; c++) {
            if(vowel.count(c)) continue;
            if(wordSet.count(c)) cnt++;
        }
        return cnt != 0;
    }
};