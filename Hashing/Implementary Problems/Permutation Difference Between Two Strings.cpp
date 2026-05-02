class Solution {
public:
    int findPermutationDifference(string s, string t) {
       unordered_map<char, pair<int, int>> mpp;
       int n1= s.size(), n2 = t.size(), ans = 0;

       for(int i = 0; i < n1; i++)mpp[s[i]].first = i;
       for(int i = 0; i < n2; i++)mpp[t[i]].second = i;

       for(auto& it : mpp){
            ans += abs(it.second.first - it.second.second);
       }
       return ans;
    }
};