#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int v)
    {
        data = v;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> preOrder)
{
    idx++;
    if (preOrder[idx] == -1)
        return NULL;

    Node *root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}



int maxTime = 0;
vector<int> answerPath;

int solve(Node* root, int target, int &dist,
          vector<int> &deepestPath,
          vector<int> &tempPath) {

    if (!root) {
        dist = -1;
        return 0;
    }

    if (root->data == target) {
        dist = 0;

        if ((int)deepestPath.size() > maxTime) {
            maxTime = deepestPath.size();
            answerPath = deepestPath;
        }

        return 1;
    }

    int leftDist = -1, rightDist = -1;
    vector<int> leftPath, rightPath;

    int leftHeight = solve(root->left, target, leftDist, leftPath, tempPath);
    int rightHeight = solve(root->right, target, rightDist, rightPath, tempPath);

    // Build deepest path for current node
    if (leftHeight > rightHeight) {
        deepestPath = leftPath;
    } else {
        deepestPath = rightPath;
    }

    deepestPath.insert(deepestPath.begin(), root->data);

    // If target in left subtree
    if (leftDist != -1) {
        dist = leftDist + 1;

        if (dist + rightHeight > maxTime) {
            maxTime = dist + rightHeight;

            answerPath.clear();
            answerPath.push_back(target);

            // Path upward
            Node* curr = root;
            answerPath.push_back(curr->data);

            // Path downward (right subtree)
            vector<int> downPath = rightPath;
            for (int x : downPath)
                answerPath.push_back(x);
        }
    }

    // If target in right subtree
    else if (rightDist != -1) {
        dist = rightDist + 1;

        if (dist + leftHeight > maxTime) {
            maxTime = dist + leftHeight;

            answerPath.clear();
            answerPath.push_back(target);
            answerPath.push_back(root->data);

            vector<int> downPath = leftPath;
            for (int x : downPath)
                answerPath.push_back(x);
        }
    }

    return 1 + max(leftHeight, rightHeight);
}

// Wrapper
vector<int> longestBurnPath(Node* root, int target) {
    int dist = -1;
    vector<int> deepestPath, tempPath;
    solve(root, target, dist, deepestPath, tempPath);
    return answerPath;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);
    vector<int> burnPath = longestBurnPath(root, 2);
    cout << "Longest burn path: ";
    for (int x : burnPath)      cout << x << " ";
    cout << endl;
    return 0;
}