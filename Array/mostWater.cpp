class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater= 0;
        int lp= 0, rp= height.size()-1;
        while(lp < rp) {
            int ht= min(height[rp], height[lp]);
            maxWater= max(maxWater, (rp - lp) * ht);
            if(ht == height[lp]) lp++;
            else rp--;
        }
        return maxWater;
    }
};