bool canJump(vector<int>& nums) {
        int maxIdx = 0;
        for(int i=0; i<nums.size(); i++){
            if(i > maxIdx) return false;
            maxIdx = max(maxIdx, i + nums[i]);
            if(maxIdx>=nums.size()-1) return true;
        }
        return true;
    }