class Solution {
private:
    int isPossible(vector<int>&nums , int day , int m , int k , int n){
        int cnt = 0 , noOfB = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] <= day)cnt++;
            else{
                noOfB += cnt / k;
                cnt = 0;
            }
        }
        noOfB += cnt / k;
        return noOfB >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long val = m * 1l * k * 1l;
        if(n < val) return -1;

        int low = INT_MAX , high = INT_MIN , ans = -1;
        for(int i = 0 ; i < n ; i++){
            low = min(low , bloomDay[i]);
            high = max(high , bloomDay[i]);
        }

        while(low <= high){
            int mid = (low + high) / 2;

            if(isPossible(bloomDay , mid , m , k , n)){
                high = mid - 1;
                ans = mid ;
            }else low = mid + 1;
        }
        return ans;
    }
};