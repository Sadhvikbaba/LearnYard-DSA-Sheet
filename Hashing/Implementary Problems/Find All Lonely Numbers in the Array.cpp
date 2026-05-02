class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for(int& it : nums) mpp[it]++;

        vector<int> ans;

        for(auto &it : mpp){
            if(it.second == 1 && mpp.find(it.first - 1) == mpp.end() && mpp.find(it.first + 1) == mpp.end()) ans.push_back(it.first);
        }

        return ans;
    }
};