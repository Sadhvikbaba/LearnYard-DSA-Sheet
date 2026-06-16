class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size() - 1, cnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == nums[i + 1]) {
                nums[i + 1] = 0;
                nums[i] *= 2;
                i++;
            }
        } 
        vector<int> ans;

        for(const int& it : nums) {
            if(it != 0) ans.push_back(it);
        }
        while(ans.size() <= n ) ans.push_back(0);

        return ans;
    }
};