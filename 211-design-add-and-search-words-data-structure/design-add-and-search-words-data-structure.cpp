class WordDictionary {
private:
    map<int, vector<string>> mp;
    bool isEqual(string &a, string &b) {
        int n = a.size();
        for(int i=0; i<n; i++) {
            if(a[i] == '.') continue;
            if(a[i] != b[i]) return false;
        }
        return true;
    }
public:
    WordDictionary() {
    }
    void addWord(string word) {
        mp[word.size()].push_back(word);
        return;
    }
    bool search(string word) {
        int n = word.size();
        if(mp[n].empty()) return false;
        for(string &it : mp[n]) {
            if(isEqual(word, it)) return true;
        }
        return false;
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */