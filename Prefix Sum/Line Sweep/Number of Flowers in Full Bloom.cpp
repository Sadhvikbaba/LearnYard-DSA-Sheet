class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start, end, ans;

        for(const vector<int>& it : flowers) {
            start.push_back(it[0]);
            end.push_back(it[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        for(const int& it : people) {
            int floStart = upper_bound(start.begin(), start.end(), it) - start.begin();
            int floDead = lower_bound(end.begin(), end.end(), it) - end.begin();
            ans.push_back(floStart - floDead);
        }

        return ans;
    }
};