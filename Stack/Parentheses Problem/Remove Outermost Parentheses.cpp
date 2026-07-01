class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans = "";

        for(const char& ch : s) {
            if(ch == '(') {
                cnt++;
                if(cnt == 1) continue;
            } else {
                cnt--;
                if(cnt == 0) continue;
            }
            ans.push_back(ch);
        }
        return ans;
    }
};