bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL) return p==q;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && p->val==q->val;
    }