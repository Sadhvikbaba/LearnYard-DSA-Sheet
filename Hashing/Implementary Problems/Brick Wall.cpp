class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> mpp;

        int rows = wall.size();

        for (const auto& row : wall) {
            long long sum = 0;

            for (int i = 0; i < row.size() - 1; i++) {
                sum += row[i];
                mpp[sum]++;
            }
        }

        int maxi = 0;
        for (auto& it : mpp) {
            maxi = max(maxi, it.second);
        }

        return rows - maxi;
    }
};