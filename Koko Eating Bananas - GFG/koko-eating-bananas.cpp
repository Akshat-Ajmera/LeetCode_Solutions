//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int Solve(int n, vector<int> &piles, int hr) {
        long long l=1, h=*max_element(piles.begin(),piles.end()), m, mxm, ans=h;
        while(l<=h) {
            m = ((h-l)/2)+l;
            mxm = 0;
            for(int i=0; i<n; i++) {
                mxm += (piles[i]/m) + ((piles[i]%m)!=0);
            }
            if(mxm <= hr) {
                ans = m;
                h = m-1;
            }
            else {
                l = m+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends