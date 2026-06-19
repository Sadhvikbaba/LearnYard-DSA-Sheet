class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int r, int c) {
        vector<vector<int>> ans;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                ans.push_back({i, j});
            }
        }

        sort(ans.begin(), ans.end(), [&](vector<int>& a, vector<int>& b){
            return abs(a[0] - r) + abs(a[1] - c) < abs(b[0] - r) + abs(b[1] - c);
        });
        return ans;
    }
};