class Solution {
public:
   std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
       int n = intervals.size();
      
       // Sort intervals based on start time
       std::sort(intervals.begin(), intervals.end());


       // Result list to store merged intervals
       std::vector<std::vector<int>> result;
       result.push_back(intervals[0]);


       // Iterate through remaining intervals
       for (int i = 1; i < n; i++) {
           std::vector<int>& lastInterval = result.back();


           // Check for overlap and merge if necessary
           if (lastInterval[1] >= intervals[i][0]) {
               lastInterval[1] = std::max(lastInterval[1], intervals[i][1]);
           } else {
               result.push_back(intervals[i]);
           }
       }


       return result;
   }
};

