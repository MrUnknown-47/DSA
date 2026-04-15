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

void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

bool search(Node* root, int key){
    if(root==NULL) return false;
    if(root->val==key) return true;
    if(key<root->val) return search(root->left,key);
    else return search(root->right,key);
}

Node* getIS(Node* root){
    while(root!=NULL && root->left!=NULL) root=root->left;
    return root;
}

Node* delNode(Node* root, int key){
    if(root==NULL) return root;
    if(key<root->val) root->left=delNode(root->left,key);
    else if(key>root->val) root->right=delNode(root->right,key);
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){ 
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else{
            Node* IS= getIS(root->right);
            root->val=IS->val;
            root->right=delNode(root->right,IS->val);
            
        }
    }
    return root;
}

int main(){
    vector<int> arr={5,3,7,2,4,6,8};
    Node* root=buildBST(arr);
    delNode(root,6);
    inorder(root);
    // cout<<search(root,5);
    return 0;
}