class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), left = 0, cnt = 0, ans = 0;

        for(int right = 0; right < n; right++) {
            if(nums[right] == 0)cnt++;
            
            while(cnt == 2) {
                if(nums[left] == 0)cnt--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans - 1;
    }
};