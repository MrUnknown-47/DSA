vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool LtoR = true;
        while(!q.empty()){
            int size=q.size();
            vector<int> lvl(size);
            for(int i=0; i<size; i++){
                TreeNode* cur= q.front();
                q.pop();
                int idx= LtoR? i : size-i-1;
                lvl[idx] = cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            LtoR = !LtoR;
            ans.push_back(lvl);
        }
        return ans;
    }