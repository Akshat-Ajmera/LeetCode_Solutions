class BrowserHistory {
private:
    list<string> hist;
    list<string> :: iterator it;
public:
    BrowserHistory(string homepage) {
        hist.push_back(homepage);
        it = hist.begin();
    }
    
    void visit(string url) {
        auto del = it;
        del++;
        hist.erase(del,hist.end());
        hist.push_back(url);
        it++;
    }
    
    string back(int steps) {
        while(it!=hist.begin() && steps) {
            it--;
            steps--;
        }
        return *it;
    }
    
    string forward(int steps) {
        while(it!=hist.end() && steps) {
            it++;
            steps--;
        }
        if(it==hist.end()) {
            it--;
        }
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */