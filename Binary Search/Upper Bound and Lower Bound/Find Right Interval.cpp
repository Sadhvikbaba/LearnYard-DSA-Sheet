class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for(int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end());

        vector<int> ans(n);

        for(const vector<int>& it : intervals) {
            auto temp = lower_bound(intervals.begin(), intervals.end(), it[1], [](const vector<int>&a, int val) {return a[0] < val;});

            ans[it[2]] = (temp == intervals.end()) ? -1 :(*temp)[2];
        }

        return ans;
    }
};