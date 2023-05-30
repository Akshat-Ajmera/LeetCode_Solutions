class MyHashSet {
public:
    vector<list<int>>v;
    int size;
    MyHashSet() {
        size = 100;
        v.resize(size);
    }
    int myHash(int key){
        return key%size;
    }
    list<int> :: iterator search(int key){
        int i = myHash(key);
        return find(v[i].begin(), v[i].end(), key);
    }
    void add(int key) {
        if(contains(key) == true){
            return;
        }
        int i = myHash(key);
        v[i].push_back(key);
    }
    void remove(int key) {
        int i = myHash(key);
        if(contains(key) == false){
            return;
        }
        v[i].erase(search(key));
    }
    bool contains(int key) {
        int i = myHash(key);
        if(search(key) == v[i].end()){
            return false;
        }
        else{
            return true;
        }
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */