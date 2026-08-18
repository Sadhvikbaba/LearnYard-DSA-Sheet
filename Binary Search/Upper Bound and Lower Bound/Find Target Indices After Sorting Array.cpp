class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int low = 0, high = n - 1;

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] < target) low = mid + 1;
            else high = mid;
        }

        vector<int> ans;

        for(int i = low; i < n && nums[i] == target; i++) ans.push_back(i);

        return ans;
    }
};