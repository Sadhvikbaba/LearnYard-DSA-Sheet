class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, n = nums.size();

        while(i < j) {
            while(i < n && !(nums[i] & 1))i++;
            while(j >= 0 && (nums[j] & 1))j--;
            if((i < j) && (i < n) && (j >= 0)) swap(nums[i], nums[j]);
        }
        return nums;
    }
};