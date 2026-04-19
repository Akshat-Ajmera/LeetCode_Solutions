class DataStream {
private:
    int cnt, val, K;
public:
    DataStream(int value, int k) {
        cnt = 0, val = value, K = k;
    }
    bool consec(int num) {
        if(num == val) {
            cnt++;
            return (cnt >= K) ? true : false;
        }
        else return cnt = 0;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */