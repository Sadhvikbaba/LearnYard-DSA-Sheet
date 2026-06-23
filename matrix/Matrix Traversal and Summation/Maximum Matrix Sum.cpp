class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int negCnt = 0, minAbs = INT_MAX;
        long long ans = 0;
        int rows = matrix.size(), cols = matrix[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] < 0) negCnt++;
                int absVal = abs(matrix[i][j]);
                ans += absVal;
                minAbs = min(minAbs, absVal);
            }
        }

        if(negCnt & 1) return ans - 2 * minAbs;
        return ans;
    }
};