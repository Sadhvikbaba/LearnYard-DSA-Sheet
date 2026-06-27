class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), right = 0, left = 0;
        int sum = 0, maxSum = 0;
        vector<int> count(10001);

        while(right < n) {
            count[nums[right]]++;
            sum += nums[right];

            while(count[nums[right]] > 1){
                sum -= nums[left];
                count[nums[left++]]--;
            }
            
            maxSum = max(maxSum, sum);
            right++;
        }
        return maxSum;
    }
};