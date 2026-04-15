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

void inorder(Node* root, vector<int>& arr){
    if(root==NULL) return;
    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}

Node* buitldBSTfromSorted(vector<int>& arr, int s, int e){
    if(s>e) return NULL;
    int mid=s+(e-s)/2;
    Node* root=new Node(arr[mid]);
    root->left=buitldBSTfromSorted(arr,s,mid-1);
    root->right=buitldBSTfromSorted(arr,mid+1,e);
    return root;
}

Node* merge2BST(Node* root1, Node* root2){
    vector<int> arr1, arr2;
    inorder(root1,arr1);
    inorder(root2,arr2);

    vector<int> temp;

    int i=0, j=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]) temp.push_back(arr1[i++]);
        else temp.push_back(arr2[j++]);
    }
    while(i<arr1.size()) temp.push_back(arr1[i++]);
    while(j<arr2.size()) temp.push_back(arr2[j++]);

    return buitldBSTfromSorted(temp,0,temp.size()-1);


}

