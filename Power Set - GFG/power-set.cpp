//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    ans.push_back(s);
		    int n = s.size();
		    for(int i=0; i<((1<<n)-1); i++) {
		        string subseq = "";
		        for(int j=0; j<n; j++) {
		            if(i & 1<<j) {
		                subseq += s[j];
		            }
		        }
		        if(subseq!="" ) {
		            ans.push_back(subseq);
		        }
		    }
		    sort(ans.begin(),ans.end());
		    
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends