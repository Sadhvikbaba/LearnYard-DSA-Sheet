class Solution {
public:
    int calculate(string s) {
        long long result = 0, number = 0, sign = 1;
        vector<int> st;

        for(const char& ch : s) {

            if('0' <= ch && ch <= '9') {
                number = number * 10 + (ch - '0');
            }

            if(ch == ' ') continue;
            
            if(ch == '+' || ch == '-') {
                result += sign * number;
                number = 0;
                sign = (ch == '+') ? 1 : -1;
            }

            if(ch == '(') {
                st.push_back(result);
                st.push_back(sign);
                result = 0;
                number = 0;
                sign = 1;
            } else if(ch == ')') {
                result += sign * number;
                number = 0;

                int prevSign = st.back();
                st.pop_back();

                int prevValue = st.back();
                st.pop_back();

                result = prevValue  + prevSign * result;
            }
        }
        result += sign * number;

        return result;
    }
};