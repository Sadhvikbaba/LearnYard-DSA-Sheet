class Solution {
private:
    string parseString(string& str, int& ind) {
        int n = str.size();

        string ans = "";
        ans.push_back(str[ind++]);
        while(ind < n && 'a' <= str[ind] && str[ind] <= 'z') ans.push_back(str[ind++]);
        return ans;
    }

    int parseNumber(string& str, int& ind) {
        int n = str.size();

        int ans = 0;
        while(ind < n && '0' <= str[ind] && str[ind] <= '9') {
            ans *= 10;
            ans += str[ind++] - '0';
        }
        return (ans == 0) ? 1 : ans;
    }
public:
    string countOfAtoms(string formula) {
        int n = formula.size();

        stack<map<string, int>> st;
        st.push({});
        int i = 0;

        while(i < n) {
            if(formula[i] == '(') {
                st.push({});
                i++;
            } else if(formula[i] == ')'){
                auto curr = st.top();
                st.pop();
                i++;

                int mul = parseNumber(formula, i);
                for(const auto& [atom, cnt] : curr) {
                    st.top()[atom] += mul * cnt;
                }
            } else {
                string atom = parseString(formula, i);
                int cnt = parseNumber(formula, i);

                st.top()[atom] += cnt;
            }
        }
        string ans = "";
        for(const auto&[atom, cnt] : st.top()) {
            ans += atom;
            if(cnt > 1) ans += to_string(cnt);
        }

        return ans;
    }
};