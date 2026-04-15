int ans=0;
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        ans=max(ans,left+right);
        return max(left, right) +1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return ans;
    }