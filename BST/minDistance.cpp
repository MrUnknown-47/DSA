class Solution {
public:
    TreeNode* prev= NULL;
    int minDiffInBST(TreeNode* root) {
        if(!root) return INT_MAX;

        int ans= INT_MAX;

        if(root->left){
            int leftMin = minDiffInBST(root->left);
            ans = min(ans, leftMin);
        }

        if(prev) ans = min(ans, root->val - prev->val);
        prev=root;

        if(root->right){
            int rightMin = minDiffInBST(root->right);
            ans=min(ans, rightMin);
        }

        return ans;
    }
};