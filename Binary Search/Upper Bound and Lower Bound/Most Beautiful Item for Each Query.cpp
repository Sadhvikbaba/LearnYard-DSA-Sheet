class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int n = items.size();

        for(int i = 1; i < n; i++) {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for(const int& it : queries) {
            int low = 0, high = n - 1, ans = 0;

            while(low <= high) {
                int mid = low + (high - low) / 2;

                if(items[mid][0] <= it) {
                    ans = items[mid][1];
                    low = mid + 1;
                } else high = mid - 1;
            }
            answer.push_back(ans);
        }
        return answer;
    }
};