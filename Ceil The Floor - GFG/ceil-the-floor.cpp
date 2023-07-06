//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    int top=1e7, bottom=-1;
    for(int i=0; i<n; i++) {
        if(arr[i] >= x) {
            top = min(top,arr[i]);
        }
        if(arr[i] <= x) {
            bottom = max(bottom,arr[i]);
        }
    }
    if(top==1e7) {
        return {bottom,-1};
    }
    return {bottom,top};
}