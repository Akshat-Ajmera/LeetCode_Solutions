//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
class Solution {
public:
    static bool comp(const Item &a, const Item &b) {
        return (((double)a.value/(double)a.weight)>((double)b.value/(double)b.weight));
    }
public:
    double fractionalKnapsack(int W, Item arr[], int n) {
        double ans = 0.0;
        double wt = W;
        sort(arr,arr+n,comp);
        // vector<pair<double,pair<int,int>>> v(n);
        // for(int i=0; i<n; i++) {
        //     v[i].first = ((double)arr[i].value)/(double)(arr[i].weight);
        //     v[i].second.first = arr[i].value;
        //     v[i].second.second = arr[i].weight;
        // }
        // sort(v.rbegin(),v.rend());
        for(int i=0; i<n; i++) {
            if(!wt) {
                break;
            }
            if(arr[i].weight <= wt) {
                ans += arr[i].value;
                wt -= arr[i].weight;
            }
            else {
                double val_per_wt = ((double)arr[i].value/(double)arr[i].weight);
                ans += wt*(val_per_wt);
                wt = 0.0;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends