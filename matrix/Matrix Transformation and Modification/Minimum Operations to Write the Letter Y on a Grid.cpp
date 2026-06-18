class Solution {
private :
    bool isY(int i, int j, int n) {
        if(i == j && i <= n/2) return true;
        if(i + j == n - 1 && i < j) return true;
        if(i >= n / 2 && j == n / 2) return true;
        return false;
    }
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        vector<int> nCnt(3), yCnt(3);
        int n = grid.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isY(i, j, n)) yCnt[grid[i][j]]++;
                else nCnt[grid[i][j]]++;
            }
        }
        int ans = INT_MAX;
        int totalY = yCnt[0] + yCnt[1] + yCnt[2];
        int totalN = nCnt[0] + nCnt[1] + nCnt[2];

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(i != j) {
                    ans = min(ans, (totalY - yCnt[i]) + (totalN - nCnt[j]));
                }
            }
        }
        return ans;
    }
};