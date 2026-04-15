#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int v){
        val=v;
        left=right=NULL;
    }
};

Node* insert(Node* root, int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->val) root->left=insert(root->left,val);
    else root->right=insert(root->right,val);
    return root;
}

Node* buildBST(vector<int> arr){
    Node* root=NULL;
    for(int val : arr) root=insert(root,val);
    return root;
}

class Info{
    public:
    int min, max, size;

    Info(int m1, int m2, int s){
        min=m1;
        max=m2;
        size=s;
    }
};

Info helper(Node* root){
    if(!root) return Info(INT_MAX,INT_MIN,0);

    Info left=helper(root->left);
    Info right=helper(root->right);
    
    if(root->val > left.max && root->val < right.min){
        int currMin = min(root->val, left.min);
        int currMax = max(root->val, right.max);
        int currSize = left.size + right.size + 1;

        return Info(currMin, currMax, currSize);
    }

    return Info(INT_MIN, INT_MAX, max(left.size, right.size));
}

int largestBST(Node* root){
    Info info = helper(root);
    return info.size;
}