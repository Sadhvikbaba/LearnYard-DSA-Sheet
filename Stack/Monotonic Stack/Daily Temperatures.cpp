class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n), st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && temperatures[i] > temperatures[st.back()]) {
                int idx = st.back();
                st.pop_back();
                ans[idx] = i - idx;
            }
            st.push_back(i);
        }
        return ans;
    }
};