class Solution {
public:
    int preOrder=0;
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        if(root->left){
            int leftAns = kthSmallest(root->left, k);
            if(leftAns != -1) return leftAns;
        }
        if(preOrder+1 == k) return root->val;
        preOrder++;
        if(root->right){
            int rightAns = kthSmallest(root->right, k);
            if(rightAns != -1) return rightAns;
        }
        return -1;
    }
};