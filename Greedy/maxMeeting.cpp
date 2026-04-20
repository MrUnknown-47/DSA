class Solution {
  public:
  struct Data {
   int start; 
   int end;
   int pos; 
};
bool static comp(Data val1, Data val2){
    return val1.end < val2.end;
}
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = end.size();
        if(n <= 1) return n;
        Data meetings[n];
        for(int i=0; i<n;i++){
            meetings[i].start = start[i];
            meetings[i].end = end[i];
            meetings[i].pos= i+1;
        }
        sort(meetings, meetings+n, comp);
        int cnt =1, freeTime= meetings[0].end;
        vector<int> result;
        result.push_back(meetings[0].pos);
        for(int i=1; i<n; i++){
            if(meetings[i].start > freeTime){
                result.push_back(meetings[i].pos);
                freeTime = meetings[i].end;
                cnt++;
            }
        }
        return cnt;
    }
};