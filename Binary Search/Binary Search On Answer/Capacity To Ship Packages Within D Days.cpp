class Solution {
private:
    bool isPossible(vector<int> &nums , int adays ,int capacity , int n){
        int cnt = 0;
        int days = 1;
        for(int i = 0 ; i < n ; i++){
            if(cnt + nums[i] > capacity){
                days++;
                cnt = nums[i];
            }else cnt += nums[i];
        }
        return days <= adays;
    }
public:
    int shipWithinDays(vector<int>& nums, int days) {
        int n = nums.size();
        int low = 0 , high = 0 ;
        for(int i = 0 ; i < n ; i++){
            high += nums[i];
            low = max(low , nums[i]);
        }
        while(low <= high){
            int mid = (low + high) / 2;
            if(isPossible(nums , days , mid , n))high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};