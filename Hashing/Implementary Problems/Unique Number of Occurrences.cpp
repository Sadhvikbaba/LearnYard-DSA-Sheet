class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mpp;

        for(int it : arr)mpp[it]++;
        vector<bool> check(arr.size(), false);

        for(auto& it : mpp){
            if(check[it.second])return false;
            check[it.second] = true;
        }

        return true;
    }
};