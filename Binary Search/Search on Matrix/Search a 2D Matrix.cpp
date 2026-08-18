class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();
        int high = m * matrix.size() - 1 , low = 0;
        while(low <= high){
            int mid = (low + high) / 2;
            int row = mid / m , col = mid % m;

            if(matrix[row][col] == target)return true;
            else if(matrix[row][col] < target)low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};