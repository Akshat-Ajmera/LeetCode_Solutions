struct TrieNode {
    TrieNode *links[26];
    bool flag = false;
    bool containsKey(char ch) {return (links[ch - 'a'] != NULL);}
    void set(char ch, TrieNode* node) {links[ch - 'a'] = node;}
    TrieNode* get(char ch) {return links[ch - 'a'];}
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.size(); i++) {
            if(!(curr->containsKey(word[i]))) curr->set(word[i], new TrieNode());
            curr = curr->get(word[i]);
        }
        curr->flag = true;
    }
    bool search(string word) {
        TrieNode* curr = root; 
        for(int i=0; i<word.size(); i++) {
            if(!(curr->containsKey(word[i]))) return false;
            curr = curr->get(word[i]);
        }
        return curr->flag;
    }
    bool startsWith(string prefix) {
        TrieNode* curr = root; 
        for(int i=0; i<prefix.size(); i++) {
            if(!(curr->containsKey(prefix[i]))) return false;
            curr = curr->get(prefix[i]);
        }
        return true;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */