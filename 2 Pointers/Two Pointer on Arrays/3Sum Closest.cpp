class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < n - 2; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(abs(sum - target) < abs(ans - target)) ans = sum;

                if(sum == target) return target;
                else if(sum < target) j++;
                else k--;
            }
        }
        return ans;
    }
};