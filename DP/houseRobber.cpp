class Solution {
public:
    int maxNonAdjacentSum(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n= nums.size();
        if (n == 1) return nums[0];
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

    int rob(vector<int>& nums) {
        int n= nums.size();
        if (n == 0) return 0;
        if(n==1) return nums[0];
        vector<int> temp1, temp2;
        for(int i=0; i<n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        return max(maxNonAdjacentSum(temp1), maxNonAdjacentSum(temp2));
    }
};