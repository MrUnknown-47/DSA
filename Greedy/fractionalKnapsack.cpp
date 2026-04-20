class Solution {
  public:
    struct Item{
        int val;
        int wt;
    };
        bool static comp(Item val1, Item val2){
            return (double) ((double) val1.val / (double) val1.wt) > (double) ((double) val2.val / (double) val2.wt);
        }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int W) {
        int n= val.size();
        Item arr[n];
        for(int i=0; i<n; i++){
            arr[i].val = val[i];
            arr[i].wt = wt[i];
        }
        sort(arr, arr + n, comp);
        double totVal = 0;
        for(int i=0; i<n; i++){
            if(arr[i].wt < W){
                totVal += arr[i].val;
                W -= arr[i].wt;
            } else{
                totVal += (double) (((double) arr[i].val / (double) arr[i].wt) * (double) W);
                break;
            }
        }
        return totVal;
        
    }
};
