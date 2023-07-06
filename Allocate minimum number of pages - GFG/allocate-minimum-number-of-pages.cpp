//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    int numStudents(int a[], int n, int cap) {
        int ans=0, pgs=0;
        for(int i=0; i<n; i++) {
            pgs += a[i];
            if(pgs>cap) {
                ans++;
                pgs = a[i];
            }
        }
        if(pgs) {
            ans++;
        }
        return ans;
    }
  public:
    int findPages(int a[], int n, int m) {
        if(n<m) {
            return -1;
        }
        int mn = *max_element(a,a+n), mx = accumulate(a,a+n,0), ans=0;
        while(mn<=mx) {
            int mid = (mn+mx)/2, totalStud = numStudents(a,n,mid);
            if(totalStud>m) {
                mn = mid+1;
            }
            else {
                ans = mid;
                mx = mid-1;
            }

        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends