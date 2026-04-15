#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int>& arr, int st, int mid, int end){
    int i=st, j=mid+1;
    vector<int> temp;
    int invCnt=0;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
            i++;
        } else {
            temp.push_back(arr[j++]);
            j++
            invCnt += (mid-i+1);
        }
    }
    while(i<=mid) temp.push_back(arr[i++]);
    while(j<=end) temp.push_back(arr[j++]);

    for(int k=0; k<temp.size(); k++){
        arr[st+k] = temp[k];
    }
    return invCnt;
}