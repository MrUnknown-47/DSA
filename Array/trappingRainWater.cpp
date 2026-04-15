class Solution {
public:
   int trap(vector<int>& height) {
      int n=height.size();
     
      int ans=0;
      int lmax=height[0];
      int rmax=height[n-1];


      int low=1;
      int high=n-2;
      while(low<=high)
      {
          lmax=max(lmax,height[low]);
          rmax=max(rmax,height[high]);
          if(rmax>lmax)
          ans+=lmax-height[low++];
          else
          ans+=rmax-height[high--];
      }
      return ans;
   }
};



