void allPath(TreeNode* root, string path, vector<string>& ans){
        if(root->left==NULL && root->right==NULL){
            ans.push_back(path);
            return;
        }
        if(root->left) allPath(root->left, path+"->"+to_string(root->left->val),ans);
        if(root->right) allPath(root->right, path+"->"+to_string(root->right->val),ans);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        allPath(root,to_string(root->val),ans);
        return ans;
    }