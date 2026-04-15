#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int v){
        val=v;
        next= NULL;
    }
};

Node* insertEnd(Node* root, int item) {
    Node* temp = new Node(item);
    if (root == NULL)
        return temp;

    Node* last = root;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = temp;
    return root;
}

Node* arrayToList(vector<int>& arr, int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insertEnd(root, arr[i]);
    }
    return root;
}

void printLL(Node *head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    vector<int> arr= {1,2,3,4,5};
    Node* head = arrayToList(arr, arr.size());
    printLL(head);
}

    