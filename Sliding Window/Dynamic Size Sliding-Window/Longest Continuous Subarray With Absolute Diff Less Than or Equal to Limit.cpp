class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDQ, minDQ;
        int n = nums.size();
        int ans = INT_MIN, left = 0;

        for(int i = 0; i < n; i++) {
            while(!maxDQ.empty() && nums[maxDQ.back()] <= nums[i]) maxDQ.pop_back();
            maxDQ.push_back(i);

            while(!minDQ.empty() && nums[minDQ.back()] >= nums[i]) minDQ.pop_back();
            minDQ.push_back(i);

            if(nums[maxDQ.front()] - nums[minDQ.front()] > limit) {
                if(maxDQ.front() == left) maxDQ.pop_front();
                if(minDQ.front() == left) minDQ.pop_front();

                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};