//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
private:
    int solve(int w, int wt[], int val[], int n, vector<vector<int>> &dp) {
        if(w<0) {
            return INT_MIN;
        }
        if(!n) {
            if(w >= wt[n]) {
                return dp[n][w] = val[n];
            }
            return dp[n][w] = 0;
        }
        if(dp[n][w] != -1) {
            return dp[n][w];
        }
        int a = solve(w,wt,val,n-1,dp), b = val[n]+solve(w-wt[n],wt,val,n-1,dp);
        return dp[n][w] = max(a,b);
    }
public:
    int knapSack(int W, int wt[], int val[], int n) {
        vector<vector<int>> dp(n, vector<int> (W+1, -1));
        return solve(W,wt,val,n-1,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends