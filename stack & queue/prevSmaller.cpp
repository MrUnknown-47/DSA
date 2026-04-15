#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> preSmaller(vector<int> &arr){
    stack<int> st;
    vector<int> ans(arr.size(), 0);
    for(int i=0; i<arr.size(); i++){
        while(!st.empty() && st.top() >= arr[i]) st.pop();
        if(st.empty()) ans[i] =-1;
        else ans[i] = st.tsop();
        st.push(arr[i]);
    }
    return ans;
}

int main(){
    vector<int> arr={3, 1, 0, 8 ,6};
    vector<int> ans= preSmaller(arr);
    for(int i=0; i<ans.size(); i++) cout<< ans[i]<<" ";
    return 0;
}