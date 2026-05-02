class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> st;

        for(string& str : words){
            string even = "", odd = "";
            int n = str.size();

            for(int i = 0; i < n; i++){
                if(i & 1) {
                    odd.push_back(str[i]);
                } else even.push_back(str[i]);
            }

            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());

            st.insert(even + "|" + odd);
        }

        return st.size();
    }
};