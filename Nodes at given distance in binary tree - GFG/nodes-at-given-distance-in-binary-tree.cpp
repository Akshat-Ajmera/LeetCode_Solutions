//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
class Solution {
private:
    Node* bfs(Node* root, int t) {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            if(node->data==t) {
                return node;
            }
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }
        return root;
    }

public:
    vector <int> KDistanceNodes(Node* root, int target , int k) {
        vector<int> ans;
        if(!root) {
            return ans;
        }
        Node* tgt = bfs(root,target);
        unordered_map<Node*,Node*> mp;
        unordered_set<Node*> st;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            auto node=q.front();
            q.pop();
            if(node->left) {
                mp[node->left]=node;
                q.push(node->left);
            }
            if(node->right) {
                mp[node->right]=node;
                q.push(node->right);
            }
        }
        q.push(tgt);
        st.insert(tgt);
        for(auto it=mp.begin(); it!=mp.end(); it++) {
        }
        while(!q.empty()) {
            int siz=q.size();
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
            k--;
            if(!k) {
                while(!q.empty()) {
                    auto it=q.front();
                    q.pop();
                    ans.push_back(it->data);
                }
                sort(ans.begin(),ans.end());
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends