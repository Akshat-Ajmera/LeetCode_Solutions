//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int> nums, int n, int tg) {
        int lo=0, hi=n-1, mid;
        while(lo <= hi) {
            mid = (lo+hi)/2;
            if(nums[mid] == tg) {
                return mid;
            }
            if(nums[mid] < tg) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends