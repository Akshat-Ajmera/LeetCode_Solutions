//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution {
private:
    int solve(int arr[], int n, vector<int> &dp) {
        if(n<0) {
            return 0;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        if(!n) {
            return dp[0] = arr[0];
        }
        int p = arr[n] + solve(arr,n-2,dp);
        int np = solve(arr,n-1,dp);
        return dp[n] = max(p,np);
    }
public:
    int FindMaxSum(int arr[], int n) {
        int sum=0;
        vector<int> dp(n,-1);
        return solve(arr,n-1,dp);
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends