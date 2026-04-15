int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth=0;
        while(q.size()){
            int curSize=q.size();
            unsigned long long st=q.front().second;
            unsigned long long end=q.back().second;
            maxWidth=max(maxWidth,(int)(end-st+1));
            for(int i=0; i< curSize;i++){
                auto cur=q.front();
                q.pop();
                if(cur.first->left) q.push({cur.first->left, cur.second*2+1}); 
                if(cur.first->right) q.push({cur.first->right, cur.second*2+2}); 
            }

        }
        return maxWidth;
    }