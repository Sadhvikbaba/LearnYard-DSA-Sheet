class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n); 
        long long totalSum = accumulate(nums.begin(), nums.end(), 0);
        long long leftSum = 0;
        for(int i = 0; i < n; i++) {
            int rightSum = totalSum - leftSum - nums[i];
            ans[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }
        return ans;
    }
};