class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans = prices, st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && st.back() > prices[i]) st.pop_back();

            if(!st.empty()) ans[i] -= st.back();
            st.push_back(prices[i]);
        }
        return ans;
    }
};