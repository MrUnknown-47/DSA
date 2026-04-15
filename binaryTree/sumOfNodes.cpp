int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        return sumNumbers(root->left) + sumNumbers(root->right) + root->val;
    }