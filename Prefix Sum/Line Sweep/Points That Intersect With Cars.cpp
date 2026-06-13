class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> count(102);
        int n = nums.size(), ans = 0;

        for(const vector<int>& it : nums) {
            count[it[0]]++;
            count[it[1] + 1]--;
        }
        for(int i = 1; i < 102; i++) {
            count[i] += count[i - 1];
            if(count[i] > 0) ans++;
        }
        return ans;
    }
};