//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
    string reverseWords(string s) {
        vector<string> v;
        string a;
        stringstream ss(s);
        while(getline(ss,a,'.')) {
            v.push_back(a);
        }
        string ans = "";
        int n = v.size();
        ans += v[n-1];
        for(int i=n-2; i>=0; i--) {
            ans += "." + v[i];
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends