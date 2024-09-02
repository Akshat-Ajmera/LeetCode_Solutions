class Solution {
private:
    int solve(map<int, set<int>> &mp, vector<bool> &vis, vector<int> &arr) {
        queue<pair<int, int>> que;
        que.push({0, 0});
        while(!que.empty()) {
            auto it = que.front();
            que.pop();
            int idx = it.first;
            int jmp = it.second;
            if(idx == arr.size()-1) return jmp;
            vis[idx] = true;
            if(idx + 1 < arr.size() && !vis[idx + 1]) que.push({idx+1, jmp+1});
            if(idx - 1 >= 0 && !vis[idx - 1]) que.push({idx-1, jmp+1});
            for(auto &ind : mp[arr[idx]]) {
                if(ind == idx || vis[ind]) continue;
                que.push({ind, jmp+1});
                mp[arr[idx]].erase(ind);
            }
        }
        return -1;
    }
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        map<int, set<int>> mp;
        for(int i=0; i<n; i++) {
            mp[arr[i]].insert(i);
        }
        vector<bool> vis(n, false);
        return solve(mp, vis, arr);
    }
};