class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
       int n = nums.size();
       unordered_map<int, int> cnt;
       cnt[0] = 1;
       bool available = false;
       int balance = 0, ans = 0;

       for(int i = 0; i < n; i++) {
        if(nums[i] > k) balance++;
        else if(nums[i] < k) balance--;
        else available = true;

        if(available) ans += cnt[balance] + cnt[balance - 1];
        else cnt[balance]++;
       }

       return ans;
    }
};