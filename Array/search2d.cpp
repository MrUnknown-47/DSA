class Solution {
public:
    bool searchInRow(vector<vector<int>>& mat, int target, int row) {
        int n=mat[0].size();
        int st=0, end=n-1;
        
        while(st <= end) {
            int mid= st + (end-st)/2;

            if(mat[row][mid] == target) return true;
            else if(target < mat[row][mid]) end=mid-1;
            else st = mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        int startRow = 0, endRow = m-1;
        while(startRow <= endRow) {
            int midRow = startRow + (endRow - startRow)/2;
            if(target >= mat[midRow][0] && target <= mat[midRow][n-1]) return searchInRow(mat, target, midRow);
            else if(target < mat[midRow][0]) endRow=midRow-1;
            else startRow = midRow+1;

        } 
        return false;
    }
};