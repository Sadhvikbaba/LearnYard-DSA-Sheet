class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = INT_MIN, n = points.size();
        deque<pair<int, int>> dq;

        for(int i = 0; i < n; i++) {
            while(!dq.empty() && points[i][0] - dq.front().second > k) dq.pop_front();

            if(!dq.empty()) ans = max(ans, dq.front().first + points[i][0] + points[i][1]);

            int curr = points[i][1] - points[i][0];

            while(!dq.empty() && dq.back().first <= curr) dq.pop_back();

            dq.push_back({curr, points[i][0]});
        }
        return ans;
    }
};