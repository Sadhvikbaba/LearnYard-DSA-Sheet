class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        int maxCnt = INT_MIN, ans;

        for(int i = 0; i < rows; i++) {
            int cnt = 0;
            for(int j = 0; j < cols; j++){
                if(mat[i][j]) cnt++;
            }
            if(maxCnt < cnt) {
                maxCnt = cnt;
                ans = i;
            }
        }
        return {ans, maxCnt};
    }
};