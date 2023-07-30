//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
        void solve(vector<string> &ans, string s, int ind, string &subseq) {
            if(ind >= s.size()) {
                ans.push_back(subseq);
                return;
            }
            subseq.push_back(s[ind]);
            solve(ans,s,ind+1,subseq);
            subseq.pop_back();
            solve(ans,s,ind+1,subseq);
        }
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    string subseq = "";
		    int ind = 0;
		    solve(ans,s,ind,subseq);
		    ans.pop_back();
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