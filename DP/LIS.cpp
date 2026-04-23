#include<iostream>
#include<vector>
using namespace std;

int LIS(vector<int> & arr){
    int n = arr.size();
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i=0; i<n; i++){
        if(arr[i] > ans.back()) ans.push_back(arr[i]);
        else{
            int st =0, end=ans.size()-1;
            int res=arr.size();
            while(st<=end){
                int mid = st + (end-st)/2;
                if(ans[mid] >= arr[i]){
                    res = mid;
                    end = mid -1;
                } else st = mid +1;
            }
            ans[res] =arr[i];
        }
    }
    return ans.size();
}


int main(){
    vector<int> arr= {10,9,2,5,3,7,101,18};
    cout<<"LIS is : "<< LIS(arr)<<endl;
    return 0;
}