class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, left = 0, right = k;

        for(int i = 0; i < k; i++) sum += nums[i];
        double ans = (double)sum / k;

        while(right < nums.size()) {
            sum += nums[right++];
            sum -= nums[left++];
            ans = max(ans, (double)sum / k);
        }
        return ans;
    }
};