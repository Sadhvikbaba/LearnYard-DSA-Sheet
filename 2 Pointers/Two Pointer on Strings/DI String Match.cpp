class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> ans(n);
        int low = 0, high = n;

        for(int i = 0; i < n; i++){
            if(s[i] == 'I') ans[i] = low++;
            else ans[i] = high--;
        }
        if(s.back() == 'I') ans.push_back(low);
        else ans.push_back(high);
        return ans;
    }
};