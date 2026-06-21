class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size(), m = bank[0].size();
        int ans = 0, prevCnt = 0;

        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < m; j++) {
                if(bank[i][j] == '1') cnt++;
            }
            
            ans += prevCnt * cnt;
            if(cnt != 0) prevCnt = cnt;
        }
        return ans;
    }
};