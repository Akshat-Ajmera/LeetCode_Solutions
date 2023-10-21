//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
	int findOnce(int nums[], int n) {
        int lo = 0, hi = n-1, mid;
        if(n==1 || nums[0] != nums[1]) {
            return nums[0];
        }
        if(nums[n-2] != nums[n-1]) {
            return nums[n-1];
        }
        while(lo <= hi) {
            mid = (lo+hi)/2;
            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]) {
                return nums[mid];
            }
            if(((mid%2) && nums[mid] == nums[mid-1]) || (!(mid%2) && nums[mid] == nums[mid+1])) {
                lo = mid+1;
            }
            else if(((mid%2) && nums[mid] == nums[mid+1]) || (!(mid%2) && nums[mid] == nums[mid-1])) {
                hi = mid-1;
            }
        }
        return -1;
	}
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends