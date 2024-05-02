class RandomizedSet {
private:
    unordered_set<int> st;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        bool flag = (st.find(val) == st.end());
        st.insert(val);
        return flag;
    }
    
    bool remove(int val) {
        bool flag = (st.find(val) != st.end());
        st.erase(val);
        return flag;
    }
    
    int getRandom() {
        int n = st.size(), i = 0, ans = 0;
        int num = (rand() % n);
        for(auto it = st.begin(); (it != st.end()); it++) {
            if(i == num) ans = *it;
            i++;
        }
        return ans;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */