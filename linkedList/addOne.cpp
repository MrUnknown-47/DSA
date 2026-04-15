#include<vector>
#include<iostream>
using namespace std;

    int addOneUtil(vector<int> &result, int i) {
        if (i>result.size()-1) return 1;
        
        int carry = addOneUtil(result, i+1);  
        int sum = result[i] + carry;
        result[i] = sum % 10;
        return sum / 10;  
}
vector<int> addOne(vector<int> arr) {
    vector<int> result=arr;
    int carry = addOneUtil(result,0);

    if (carry) {
        result.insert(result.begin(),carry);
    }

    return result;
}

int main(){
    vector<int> arr= {9,9,9};
    vector<int> res= addOne(arr);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }  
    return 0;
}