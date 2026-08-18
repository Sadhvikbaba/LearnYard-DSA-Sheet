class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> candles, ans, prefix(s.size() + 1, 0);
        int n = s.size();

        for(int i = 0; i < n; i++) {
            if(s[i] == '|') candles.emplace_back(i);
            
            prefix[i + 1] = prefix[i] + (s[i] == '*');
        }

        for(const vector<int>& it : queries) {
            int l = lower_bound(candles.begin(), candles.end(), it[0]) - candles.begin();
            int r = upper_bound(candles.begin(), candles.end(), it[1]) - candles.begin() - 1;

            if(l <= r) ans.emplace_back(prefix[candles[r]] - prefix[candles[l]]);
            else ans.push_back(0);
        }
        
        return ans;
    }
};