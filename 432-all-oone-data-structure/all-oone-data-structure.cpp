class AllOne {
private:
    map<int, set<string>> mp0;
    map<string, int> mp1;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        mp1[key]++;
        int cnt = mp1[key];
        if(cnt > 1) mp0[cnt-1].erase(key);
        mp0[cnt].insert(key);
        if(mp0[cnt-1].empty()) mp0.erase(cnt-1); 
    }
    
    void dec(string key) {
        mp1[key]--;
        int cnt = mp1[key];
        if(cnt) mp0[cnt].insert(key);
        mp0[cnt+1].erase(key);
        if(mp0[cnt+1].empty()) mp0.erase(cnt+1); 
    }
    
    string getMaxKey() {
        if(mp0.empty()) return "";
        return *(((*(--mp0.end())).second).begin());
    }
    
    string getMinKey() {
        if(mp0.empty()) return "";
        return *(((*mp0.begin()).second).begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */