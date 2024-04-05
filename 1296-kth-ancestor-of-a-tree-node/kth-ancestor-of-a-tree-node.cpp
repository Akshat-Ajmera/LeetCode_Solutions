// class TreeAncestor {
// private:
//     vector<vector<int>> ancestor;
//     int log;
// public:
//     TreeAncestor(int n, vector<int>& parent) {
//         log = (int)log2(n) + 1;
//         if(floor(log2(n) == ceil(log2(n)))) log--;
//         ancestor.resize(n, vector<int> (log, -1));
//         for(int i=0; i<n; i++) ancestor[i][0] = parent[i];
//         for(int j=1; j<log; j++) {
//             for(int i=0; i<n; i++) {
//                 if(ancestor[i][j-1] != -1) {
//                     ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
//                 }
//             }
//         }
//     }
//     int getKthAncestor(int node, int k) {
//         int ans = node;
//         for(int i=0; i<log2(k)+1; i++) {
//             if(!(k & (1 << i))) continue;
//             ans = ancestor[ans][i];
//             if(ans == -1) return -1;
//         }
//         return ans;
//     }
// };

class TreeAncestor {
public:
    vector<vector<int>> dp;
    TreeAncestor(int n, vector<int>& parent) {
        dp.resize(n,vector<int>(20,-1));
        for(int i=0;i<n;i++)dp[i][0]=parent[i];
        for(int i=1;i<20;i++){
            for(int j=0;j<n;j++){
                if(dp[j][i-1]!=-1)
                    dp[j][i]=dp[dp[j][i-1]][i-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=19;i>=0;i--){
            if((k>>i)&1)node=dp[node][i];
            if(node==-1)return -1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */