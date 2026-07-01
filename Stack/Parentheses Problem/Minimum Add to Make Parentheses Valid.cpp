class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0, ans = 0;

        for(const char& ch : s) {
            if(ch == '(') {
                cnt++;
            } else {
                if(cnt == 0) ans++;
                else cnt--;
            }
        }
        return cnt + ans;
    }
};