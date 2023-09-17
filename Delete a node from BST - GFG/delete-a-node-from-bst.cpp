//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

struct Node* deleteNode(struct Node* root, int key);

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder(Node* root, vector<int>& v) {
    if (root == NULL) return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        root1 = deleteNode(root1, k);
        vector<int> v;
        inorder(root1, v);
        for (auto i : v) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

pair<Node*,Node*> nodeSearch(Node* pnt, Node* root, int x) {
    if(!root) {
        return {NULL,NULL};
    }
    if(root->data == x) {
        return {pnt,root};
    }
    else if(root->data > x) {
        return nodeSearch(root,root->left,x);
    }
    else {
        return nodeSearch(root,root->right,x);
    }
}

Node* findLastRight(Node* node) {
    if(node->right) {
        return findLastRight(node->right);
    }
    else {
        return node;
    }
}

Node* deleteNode(Node *root, int x) {
    if(!root) {
        return NULL;
    }
    Node* Root = root;
    pair<Node*,Node*> it = nodeSearch(root,root,x);
    Node* node = it.second;
    Node* parent = it.first;
    if(!node) {
        return Root;
    }
    if(node == root) {
        if(!(node->left)) {
            return root->right;
        }
        else if(!node->right) {
            return root->left;
        }
        Node* last = findLastRight(node->left);
        last->right = root->right;
        return root->left;
    }
    bool lCheck = (parent->left == node);
    Node* last = NULL;
    if(node->left) {
        last = findLastRight(node->left);
        if(lCheck) {
            parent->left = node->left;
        }
        else {
            parent->right = node->left;
        }
        if(node->right) {
            last->right = node->right;
        }
    }
    else if(node->right) {
        if(lCheck) {
            parent->left = node->right;
        }
        else {
            parent->right = node->right;
        }
    }
    return Root;
}
