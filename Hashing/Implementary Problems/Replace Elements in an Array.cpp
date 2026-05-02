class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> mpp;
        int n = operations.size();

        for(int i = n - 1; i >= 0; i--){
            int oldVal = operations[i][0];
            int newVal = operations[i][1];

            if(mpp.find(newVal) != mpp.end()){
                mpp[oldVal] = mpp[newVal];
            } else {
                mpp[oldVal] = newVal;
            }
        }

        for(int& it : nums){
            if(mpp.find(it) != mpp.end()) it = mpp[it];
        }

        return nums;
    }
};