class Solution {
20public:
21    Node* connect(Node* root) {
22        if(!root || !root->left) return root;
23        queue<Node *> q;
24
25    q.push(root);
26    q.push(NULL);
27
28    Node* prev=NULL;
29    while (q.size() > 0)
30    {
31        Node *curr = q.front();
32        q.pop();
33        if (curr == NULL)
34        {
35            if (q.empty())
36            {
37                break;
38            }
39            q.push(NULL);
40        }
41
42        else{
43            if(curr->left)
44                q.push(curr->left);
45            if(curr->right)
46                q.push(curr->right);
47            if(prev != NULL)
48                prev->next = curr;
49        }
50        prev=curr;
51    }
52    return root;
53    }
54};