class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        vector<pair<int, int>> st;
        long long ans = 0;

        for(const int& it : nums) {

            while(!st.empty() && st.back().first < it) st.pop_back();

            if(!st.empty() && st.back().first == it) {
                ans += st.back().second++;
            } else st.push_back({it, 1});
        }
        return ans + nums.size();
    }
};