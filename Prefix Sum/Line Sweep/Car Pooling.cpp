class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> prefix(1001);

        for(const vector<int>& trip : trips) {
            if(trip[0] > capacity) return false;
            prefix[trip[1]] += trip[0];
            prefix[trip[2]] -= trip[0];
        }

        for(int i = 1; i < 1001; i++) {
            prefix[i] += prefix[i - 1];
            if(prefix[i] > capacity) return false;
        }
        return true;
    }
};