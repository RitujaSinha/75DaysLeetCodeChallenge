class Solution {
public:
    bool findTarget(int row, int target, vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();

        int st = 0, end = n-1;
        while(st <= end){
            int mid = st + (end-st)/2;

            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] > target) end = mid-1;
            else st= mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int st = 0, end= m-1;

        while(st <= end){
            int mid = st + (end-st)/2;

            if(matrix[mid][0] > target){
                end= mid-1;
            } else if(matrix[mid][n-1] < target){
                st = mid+1;
            } else{
                return findTarget(mid, target, matrix);
            }
        }
        return false;
    }
};

// m*n

// non-decreasing kinda asecnding 
// first element of each row is greather than last in


// 1 2 3
// 5 6 9  5 > 3

// binary search o
