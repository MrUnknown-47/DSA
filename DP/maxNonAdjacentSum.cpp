class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n= nums.size();
        int prev= nums[0], prev2=0;
        for(int i=1; i<n; i++){
            int include = nums[i];
            if(i>1) include=nums[i] + prev2;

            int exclude= 0 + prev;

            int curi = max(include, exclude);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
};