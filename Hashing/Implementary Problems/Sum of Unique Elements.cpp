class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mpp;

        for(int& it : nums){
            mpp[it]++;
        }

        for(auto& it : mpp){
            if(it.second == 1)ans += it.first;
        }

        return ans;
    }
};