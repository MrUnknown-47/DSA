class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n= arr.size();
        if(n <= 1) return n;
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int i=1, j=0;
        int cnt =1, maxCnt=1;
        while(i<n && j<n){
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
