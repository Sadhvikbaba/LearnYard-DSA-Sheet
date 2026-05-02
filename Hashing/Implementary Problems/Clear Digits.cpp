class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        string ans = "";

        for(char& ch : s){
            if(ch >= '0' && ch <= '9'){
                st.pop();
            } else st.push(ch);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};