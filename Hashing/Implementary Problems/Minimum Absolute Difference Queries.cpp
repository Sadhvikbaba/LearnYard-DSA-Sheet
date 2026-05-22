class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> prefix(n + 1, vector<int>(101, 0));

        for(int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1];
            prefix[i][nums[i - 1]]++;
        }

        vector<int> ans;

        for(auto& temp : queries) {
            int l = temp[0];
            int r = temp[1];

            int prev = -1;
            int mini = INT_MAX;

            for(int i = 1; i < 101; i++) {
                if(prefix[r + 1][i] - prefix[l][i] > 0) {
                    if(prev != -1) mini = min(mini, i - prev);
                    prev = i;
                }
            }

            if(mini == INT_MAX) ans.push_back(-1);
            else ans.push_back(mini);
        }

        return ans;
    }
};