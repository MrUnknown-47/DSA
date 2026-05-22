#include<iostream>
#include<vector>
using namespace std;

int frogJumpWithKDistance(vector<int>& heights, int k){
    int n = heights.size();
    vector<int> dp(n, -1);
    dp[0] = 0;
    for(int i=1; i<n; i++){
        int minSteps = INT_MAX;
        for(int j=1; j<=k; j++){
            if(i-j >= 0){
                int jumps = dp[i-j] + abs(heights[i] - heights[i-j]);
                minSteps = min(minSteps, jumps);
            } 
        }
        dp[i] = minSteps;
    }
    return dp[n-1];
}

int main(){
    vector<int> height{30, 10, 60, 10, 60, 50};
    int k = 2;
    cout<< frogJumpWithKDistance(height, k) << endl;
    return 0;
}