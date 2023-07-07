//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    int totalDays(int a[], int n, int cap) {
        int days = 0, wt = 0;
        for(int i=0; i<n; i++) {
            wt += a[i];
            if(wt > cap) {
                days++;
                wt = a[i];
            }
        }
        if(wt) {
            days++;
        }
        return days;
    }
  public:
    int leastWeightCapacity(int a[], int n, int d) {
        int mn = *max_element(a,a+n), mx = accumulate(a,a+n,0), mid, days;
        while(mn <= mx) {
            mid = (mn+mx)/2;
            days = totalDays(a, n, mid);
            if(days>d) {
                mn = mid+1;
            }
            else {
                mx = mid-1;
            }
        }
        return mn;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends