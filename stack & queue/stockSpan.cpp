#include<iostream>
#include<vector>
using namespace std;

vector<int> stockSpan(vector<int> &price){
    stack<int> st;
    vector<int> ans(price.size(), 0);
    
    for(int i=0; i < price.size(); i++){
        while(!st.empty() && price[st.top()] <= price[i]) st.pop();
        if(st.empty()) ans[i]= i+1;
        else ans[i]= i-st.top();
        st.push(i);
    }
    return ans;
}

void getAns(vector<int> &price){
    vector<int> ans= stockSpan(price);
    for(int i=0; i < ans.size(); i++) cout<< ans[i]<<" ";
}

int main(){
    vector<int> price ={100, 80, 70, 60, 65, 75, 115};
    getAns(price);
    return 0;
}