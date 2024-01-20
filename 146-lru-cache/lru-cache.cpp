class LRUCache {
private:
    int cap, siz;
    list<pair<int,int>> lt;
    map<int,list<pair<int,int>>::iterator> mp;
public:
    LRUCache(int capacity) {
        cap = capacity;
        siz = 0;
    }
    int get(int key) {
        auto it = mp.find(key);
        if(it != mp.end()) {
            auto it1 = it->second;
            int val = it1->second;
            lt.erase(it1);
            mp.erase(it);
            lt.push_back({key,val});
            mp[key] = --lt.end();
            return val;
        }
        return -1;
    }
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it != mp.end()) {
            auto it1 = it->second;
            lt.erase(it1);
            mp.erase(it);
            lt.push_back({key,value});
            mp[key] = --lt.end();
        }
        else {
            if(siz < cap) {
                lt.push_back({key,value});
                auto it1 = --lt.end();
                mp[key] = it1;
                siz++;
            }
            else if(siz == cap) {
                auto it1 = lt.begin();
                int k = it1->first;
                lt.pop_front();
                mp.erase(k);
                lt.push_back({key,value});
                auto it2 = --lt.end();
                mp[key] = it2;
            }
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */