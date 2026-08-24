class Solution {
private:
    int sumByD(vector<int> &nums , int limit , int n){
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += (nums[i] + limit - 1) / limit;
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if(n > threshold)return -1;
        int high = *max_element(nums.begin() , nums.end()) , low = 1;
        while(low <= high){
            int mid = (low + high) / 2;

            if(sumByD(nums , mid , n) <= threshold)high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};