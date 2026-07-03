class Solution {
private:
    void process(char sign, int number, vector<int>& st) {
        if(sign == '+') st.push_back(number);
        else if(sign == '-') st.push_back(-number);
        else if(sign == '*') st[st.size() - 1] *= number;
        else st[st.size() - 1] /= number;
    }
    
public:
    int calculate(string s) {
        int number = 0;
        char sign = '+';
        vector<int> st;

        for(const char& ch : s) {
            if('0' <= ch && ch <= '9') {
                number = number * 10 + (ch - '0');
            }

            if(!('0' <= ch && ch <= '9') && ch != ' ') {
                process(sign, number, st);

                sign = ch;
                number = 0;
            }
        }

        process(sign, number, st);

        int ans = accumulate(st.begin(), st.end(), 0LL);

        return ans;
    }
};