//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int catchThieves(char arr[], int n, int k) {
        vector<int> qT, qP;
        int count = 0, cntP = 0, cntT = 0;
        for(int i=0; i<n; i++) {
            if(arr[i] == 'T') {
                qT.push_back(i);
                cntT++;
            }
            else {
                qP.push_back(i);
                cntP++;
            }
        }
        int t = 0, p = 0;
        while(t<qT.size() && p < qP.size()) {
            if(abs(qT[t] - qP[p]) <= k) {
                count++;
                t++;
                p++;
            }
            else if(qT[t] > qP[p]) {
                p++;
            }
            else {
                t++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 


// } Driver Code Ends