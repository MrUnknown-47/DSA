#include <iostream>
#include <queue>
#include <vector>
#include<map>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int v)
    {
        val = v;
        left = right = NULL;
    }
};

static int idx = -1;
Node *buildTree(vector<int> preOrder)
{
    idx++;
    if (preOrder[idx] == -1)
        return NULL;

    Node *root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}

void topView(Node *root)
{
    queue<pair<Node *, int>> q;
    map<int, int> mpp;


    q.push({root, 0});
    while (q.size() > 0)
    {
        Node *curr = q.front().first;
        int currHD= q.front().second;

        q.pop();
        
        if(mpp.find(currHD) == mpp.end()) mpp[currHD]=curr->val;

        if (curr->left != NULL)
            q.push({curr->left, currHD-1});
        if (curr->right != NULL)
            q.push({curr->right, currHD+1});
    }

    for(auto it: mpp) cout<<it.second<<" ";
    cout << endl;
}

int main(){
    vector<int> preOrder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    Node* root= buildTree(preOrder);
    topView(root);
    return 0;
}