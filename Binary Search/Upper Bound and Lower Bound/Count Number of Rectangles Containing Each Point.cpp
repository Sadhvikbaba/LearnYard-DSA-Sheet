class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> widths(101);

        for(const auto& it : rectangles) widths[it[1]].push_back(it[0]);

        for(auto& it : widths) sort(it.begin(), it.end());

        vector<int> ans;

        for(const auto& temp : points) {
            int x = temp[0], y = temp[1];
            int cnt = 0;

            for(int i = y; i < 101; i++) {
                vector<int>& arr = widths[i];

                int ind = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

                cnt += arr.size() - ind;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};