class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> match(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')') {
                match[st.top()] = i;
                match[i] = st.top();
                st.pop();
            }
        }
        string ans = "";
        int dir = 1, i = 0;

        while(i >= 0 && i < n) {
            if(s[i] == '(' || s[i] == ')') {
                i = match[i];
                dir *= -1;
            } else ans.push_back(s[i]);

            i += dir;
        }
        return ans;
    }
};