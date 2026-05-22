#include<iostream>
#include<vector>
using namespace std;

int frogJump(vector<int>& heights){
    if (heights.empty()) return 0;
    int n = (int)heights.size();
    if (n == 1) return 0;

    int prev=0, prev2=0;
    for(int i=1; i<n; i++){
        int fs = prev + abs(heights[i] - heights[i-1]);
        int ss= INT_MAX;
        if(i > 1) ss= prev2 + abs(heights[i] - heights[i-2]);
        int curr = min(fs, ss);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main(){
    vector<int> height{30, 10, 60, 10, 60, 50};
    cout << frogJump(height) << endl;
    return 0;
}