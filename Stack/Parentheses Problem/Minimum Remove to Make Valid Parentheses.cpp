class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt = 0, maxOpen = 0, close = 0;
        string ans = "";

        for(const char& ch : s) {
            if(ch == '(') cnt++;
            else if(ch == ')') {
                if(cnt == 0) continue;
                cnt--;
            }
            ans.push_back(ch);
        }

        s = "";

        for(int i = ans.size() - 1; i >= 0; i--) {
            if(ans[i] == ')') close++;
            else if(ans[i] == '(') {
                if(close == 0) continue;
                close--;
            }
            s.push_back(ans[i]);
        }
        reverse(s.begin(), s.end());

        return s;
    }
};