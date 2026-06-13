// solved this problem using binary search on answers

class Solution {
private:
    long long getCost(vector<int>& nums, vector<int>& cost, int k) {
        int n = nums.size();
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += 1ll * abs(nums[i] - k) * cost[i];
        }
        return sum;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size(), low = INT_MAX, high = INT_MIN;
        for(const int& it : nums) {
            low = min(low, it);
            high = max(high, it);
        }

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(getCost(nums, cost, mid) > getCost(nums, cost, mid + 1)) low = mid + 1;
            else high = mid;
        }

        return getCost(nums, cost, low);
    }
};