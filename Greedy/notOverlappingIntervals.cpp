class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n <= 1) return 0;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {return a[1] < b[1];});
        int cnt =0, freeTime= intervals[0][1];
        for(int i=1; i<n; i++){
            if(intervals[i][0] < freeTime) cnt++;
            else freeTime = intervals[i][1];
        }
        return cnt;
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n <= 1) return 0;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {return a[1] < b[1];});
        int cnt =1, freeTime= intervals[0][1];
        for(int i=1; i<n; i++){
            if(intervals[i][0] >= freeTime){
                cnt++;
                freeTime = intervals[i][1];
            }
        }
        return n-cnt;
    }
};