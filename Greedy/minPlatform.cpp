class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n= arr.size();
        if(n <= 1) return n;
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int i=0, j=0;
        int cnt =0, maxCnt=0;
        while(i<n){
            if(arr[i] <= dep[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            maxCnt=max(maxCnt, cnt);
        }
        return maxCnt;
    }
};
