class Solution {
  public:
    bool static comp(Job val1, Job val2){
        return val1.profit > val2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) {
        sort(arr,arr+n, comp);
        int maxDeadline= arr[0].deadline;
        for(int i=1; i<n; i++) maxDeadline = max(maxDeadline, arr[i].deadline);
        vector<int> slot(maxDeadline + 1, -1);
        int totalProfit =0, cnt=0;
        for(int i=0; i<n; i++){
            for(int j=arr[i].deadline; j>0; j--){
                if(slot[j] == -1){
                    slot[j] = i;
                    cnt++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }
        return {cnt, totalProfit};
    }
};