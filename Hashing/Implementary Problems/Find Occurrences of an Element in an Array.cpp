class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> occ;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == x)occ.push_back(i);
        }

        vector<int> ans;
        n = occ.size();

        for(int& it : queries){
            if(it > n) {
                ans.push_back(-1);
            } else ans.push_back(occ[it - 1]);
        }
        return ans;
    }
};