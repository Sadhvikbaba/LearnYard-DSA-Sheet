class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size(), leftInd = 0, rightInd = 0;
        vector<int> left(n), right(n), ans;
        left[0] = 0; right[n - 1] = 0;
        for(int i = 1; i < n; i++) {
            if(security[i - 1] >= security[i]) left[i] = left[i - 1] + 1;
            else left[i] = 0;
        }

        for(int i = n - 2; i >= 0; i--) {
            if(security[i + 1] >= security[i]) right[i] = right[i + 1] + 1;
            else right[i] = 0;
        }

        for(int i = 0; i < n; i++) {
            if(left[i] >= time && right[i] >= time) ans.push_back(i);
        }

        return ans;
    }
};