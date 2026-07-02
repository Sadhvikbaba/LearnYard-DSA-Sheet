class Solution {
private:
    void process(vector<string>& st, string& curr) {
        if(curr == "..") {
            if(!st.empty()) st.pop_back();
        } else if(curr == ".") curr.clear();
        else if(!curr.empty()) st.push_back(curr);
        curr.clear();
    }
public:
    string simplifyPath(string path) {
        vector<string> st;
        string curr = "";
        
        for(const char& ch : path) {
            if(ch == '/') {
                process(st, curr);
            } else curr += ch;
        }

        process(st, curr);

        string ans = "";

        for(const string& str : st) {
            ans.push_back('/');
            ans += str;
        }

        if(ans.empty()) return "/";

        return ans;
    }
};