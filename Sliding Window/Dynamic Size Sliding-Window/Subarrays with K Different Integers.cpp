class Solution {
private:
    int func(vector<int>& nums, int k){
        vector<int> mpp(nums.size() + 1);
        int count = 0;
        int l = 0, r = 0, cnt = 0;

        while(r < nums.size()){
            mpp[nums[r]]++;
            if(mpp[nums[r]] == 1) cnt++;

            while(cnt > k){
                mpp[nums[l]]--;
                if(mpp[nums[l++]] == 0)cnt--;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums, k) - func(nums, k - 1);
    }
};