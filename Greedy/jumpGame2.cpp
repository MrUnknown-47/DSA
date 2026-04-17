int jump(vector<int>& nums) {
        int jump = 0, l=0, r=0;
        int n= nums.size();
        while(r < n){
            int farest = 0 ;
            for(int i=l; i<r; i++){
                farest = max(farest, i + nums[i]);
            }
            l=r+1;
            r=farest;
            jump++;
        }
        
        return jump;
    }



int jump(vector<int>& nums) {
4        int jump = 0, currEnd = 0, farest = 0;
5        for(int i = 0; i < nums.size()-1; i++){
6            farest = max(farest, i + nums[i]);
7            if(i == currEnd){
8                jump++;
9                currEnd = farest;
10            }
11        }
12        return jump;
13    }