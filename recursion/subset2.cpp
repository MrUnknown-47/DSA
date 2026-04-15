class Solution {
public:
vector<vector<int>> allSubsets;
vector<int> ans;

    void getAllSubsets(vector<int>& nums, int i){
        if(i == nums.size()){
            allSubsets.push_back({ans});
            return;
        }

        ans.push_back(nums[i]);
        getAllSubsets(nums, i+1);

        ans.pop_back();

        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[idx-1]) idx++;
        
        getAllSubsets(nums, idx);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        getAllSubsets(nums, 0);
        return allSubsets;
    }
};