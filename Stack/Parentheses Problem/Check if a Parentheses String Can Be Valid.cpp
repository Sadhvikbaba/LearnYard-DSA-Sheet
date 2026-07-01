class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n & 1) return false;

        int freeRight = 0, open = 0;
        int freeClose = 0, close = 0;

        for(int i = 0; i < n; i++) {
            if(locked[i] == '0') freeRight++;
            else if(s[i] == '(') open++;
            else {
                if(open) open--;
                else if(freeRight) freeRight--;
                else return false;
            }

            int j = n - i - 1;
            if(locked[j] == '0') freeClose++;
            else if(s[j] == ')') close++;
            else {
                if(close) close--;
                else if(freeClose) freeClose--;
                else return false;
            }
        }

        return true;
    }
};