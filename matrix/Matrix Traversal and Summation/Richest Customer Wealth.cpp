class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = INT_MIN;

        for(const vector<int>& it : accounts) {
            maxi = max(accumulate(it.begin(), it.end(), 0), maxi);
        }
        return maxi;
    }
};