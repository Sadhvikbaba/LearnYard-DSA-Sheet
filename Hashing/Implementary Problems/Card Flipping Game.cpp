class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int n = fronts.size();
        unordered_set<int> st;
        for(int i = 0; i < n; i++) {
            if(fronts[i] == backs[i]) {
                st.insert(fronts[i]);
            }
        }
        int ans = INT_MAX;

        for(const int& it : fronts) {
            if(st.find(it) == st.end()) ans = min(ans, it);
        }

        for(const int& it : backs) {
            if(st.find(it) == st.end()) ans = min(ans, it);
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};