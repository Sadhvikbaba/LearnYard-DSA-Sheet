class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int cnt = 0;
        vector<int> ans;

        for(const char& ch : seq) {
            if(ch == '(') {
                ans.push_back(cnt % 2);
                cnt++;
            } else {
                cnt--;
                ans.push_back(cnt % 2);
            }
        }
        return ans;
    }
};