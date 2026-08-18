class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans, temp;

        for(const int& it : obstacles) {
            int ind = upper_bound(temp.begin(), temp.end(), it) - temp.begin();

            if(ind == temp.size()) temp.emplace_back(it);
            else temp[ind] = it;

            ans.emplace_back(ind + 1);
        }

        return ans;
    }
};