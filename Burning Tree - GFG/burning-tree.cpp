//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  private:
    Node* nodeFinder(Node* root, int k) {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            auto node=q.front();
            q.pop();
            if(node->data==k) {
                return node;
            }
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }
        return NULL;
    }
  public:
    int minTime(Node* root, int target) {
        int ans = -1, siz = 0;
        if(!root) {
            return ans+1;
        }
        Node* curr = nodeFinder(root,target);
        queue<Node*>q;
        unordered_map<Node*,Node*> mp;
        unordered_set<Node*> st;
        q.push(root);
        while(!q.empty()) {
            auto it=q.front();
            q.pop();
            if(it->left) {
                q.push(it->left);
                mp[it->left] = it;
            }
            if(it->right) {
                q.push(it->right);
                mp[it->right] = it;
            }
        }
        q.push(curr);
        st.insert(curr);
        while(!q.empty()) {
            siz = q.size();
            while(siz--) {
                auto node=q.front();
                q.pop();
                if(node->left && !st.count(node->left)) {
                    st.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && !st.count(node->right)) {
                    st.insert(node->right);
                    q.push(node->right);
                }
                if(mp.count(node) && !st.count(mp[node])) {
                    st.insert(mp[node]);
                    q.push(mp[node]);
                }
            }
            ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends