class Solution {

int func(vector<int>& nums, int n) {
    int cnt = 0;

    for(const int& it : nums) if(it >= n) cnt++;

    return cnt - n;
}
public:
    int specialArray(vector<int>& nums) {
        int low = 1, high = nums.size(), ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int val = func(nums, mid);

            if(val == 0) {
                return mid;
            } else if(val > 0) {
                low = mid + 1;
            } else high = mid - 1;
        }
        return ans;
    }
};