class MyHashMap {
public:
    vector<list<pair<int,int>>>v;
    int size;
    MyHashMap() {
        size = 100;
        v.resize(size);
    }
    int myHash(int key){
        return key%size;
    }
    list<pair<int,int>> :: iterator search(int key){
        int i = myHash(key);
        auto it = v[i].begin();
        for(it = v[i].begin(); it != v[i].end(); it++){
            if(it -> first == key){
                return it;
            }
        }
        return it;
    }
    void put(int key, int value) {
        int i = myHash(key);
        auto it1 = search(key);
        if(search(key) != v[i].end()){
            it1 -> second = value;
        }
        else{
            v[i].push_back({key, value});
        }
    }
    int get(int key) {
        int i = myHash(key);
        if(search(key) == v[i].end()){
            return -1;
        }
        return search(key) -> second;
    }
    void remove(int key) {
        int i = myHash(key);
        if(search(key) == v[i].end()){
            return;
        }
        v[i].erase(search(key));
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */