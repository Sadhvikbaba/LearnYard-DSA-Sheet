class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> prefix(101);

        for(const vector<int>& it : logs) {
            prefix[it[0] - 1950]++;
            prefix[it[1] - 1950]--;
        }

        int ans = 1950, pop = prefix[0];
        for(int i = 1; i < 101; i++) {
            prefix[i] += prefix[i - 1];
            if(pop < prefix[i]) {
                pop = prefix[i];
                ans = 1950 + i;
            }
        }
        return ans;
    }
};